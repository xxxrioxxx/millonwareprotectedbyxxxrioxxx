/*
[PREDITLE]

Jumpshot, p100, millionware on top
Awp don't need no scope, hop around don't miss a shot
7 shots in my deagle always got me lookin' evil
p100 like it's cheat-codes just need one shot never reload

I hit the edgebug jumpbug spin around and flickshot (ooh)
Didn't even see you but your skull's eating my AWP shots (ahaheahey)
I hop through vent and spin around you didn't even see me there
It's 'cause I'm rich and flexing jumping around with my millionware

[DNZ]

I'm in the sky going high
Counting seconds in the air
Catch me if you can
bouncing like a frogman
It's 778 hopping 'round with 108
I don't stand around and wait
Jumpbug and accelerate

[SONAR]

Marijuana movement trail
Hip got locked up, county jail
Sold an invite paid for bail
You be moving like a snail
interium n***as bought a rat
paid my way into nohat
you're a nothing copycat
f**king noname acrobat

khmora gave me three day ban
bhopper from pakistan
blow it up, no taliban
You wannabes are hexa stans

UID 165
Drain Gang always sleep-deprived
Autostrafing cat-to-chair
Serversiding, millionware

[STELLAR]

Hotwheels sucks gonna breakaway
Spinning on mirage (yeah)
Hit you with the 1-tap AK
Now you all applause (yuh)

Free Clifton he didn't do sh*t
All the money it's counterfeit
Never missed bench to bricks
Swerving around 64-tick
[CHORUS/PREDITLE]

Jumpshot, p100, millionware on top
Awp don't need no scope, hop around don't miss a shot
7 shots in my deagle always got me lookin' evil
p100 like it's cheat-codes just need one shot never reload

I hit the edgebug jumpbug spin around and flickshot (ooh)
Didn't even see you but your skull's eating my AWP shots (ahaheahey)
I hop through vent and spin around you didn't even see me there
It's 'cause I'm rich and flexing jumping around with my millionware

[STELLAR]

They just added in-game chat
All these n***as got my back
Getting banned like every day
Message aiden, back in black

Hitting edgebugs de_nuke
Leaving discord call me duxe
Your strafes are dog, make me puke
My Fake Backward got you juked

Sold a paste, call me woke
f**ked your momma in the throat
Your movement is a f**king joke
Kill yourself retarded bloke
Daily dose of estrogen
No autostrafe I'm genuine
Jumping shot; adrenaline
OneShot turned me feminine

[AIDEN]

Knife behind; HNS
Tracing you like GPS
I check you like it's chess
I see Brooke, she undress (I see Brooke, she undress)

Like breezetix, don't need to hear
Sound ESP, know when you're near
Bounce off your head, I disappear
I made that one jumpbug tutorial (do you guys remember that?)
*/

#pragma once
#include "../../source engine/math/vector3d.hpp"

class c_glow_manager
{
public:
	class c_glow_object
	{
	public:
		void set( float r, float g, float b, float a )
		{
			m_colour = vec3_t( r, g, b );
			m_alpha = a;
			m_render_when_occluded = true;
			m_render_when_unoccluded = false;
			m_bloom_amount = 1.0f;
		}

		void* entity( )
		{
			return m_entity;
		}

		bool unused( ) const
		{
			return m_next_slot != c_glow_object::ENTRY_IN_USE;
		}

	public:
		void* m_entity;
		vec3_t           m_colour;
		float            m_alpha;

		char             pad04[ 4 ]; //pad
		float            pad08; //confirmed to be treated as a float while reversing glow functions
		float            m_bloom_amount;
		float            m_local_zero;


		bool             m_render_when_occluded;
		bool             m_render_when_unoccluded;
		bool             m_full_bloom;
		char             m_pad09[ 1 ]; //pad


		int              m_bloom_stencil; // 0x28
		int              m_pad013; //appears like it needs to be zero  
		int              m_screen_slot; //Should be -1

										// Linked list of free slots
		int              m_next_slot;

		// Special values for GlowObjectDefinition_t::m_nNextFreeSlot
		static const int END_OF_FREE_LIST = -1;
		static const int ENTRY_IN_USE = -2;
	};

	c_glow_object* m_definitions;
	int            m_max_size;
	int            pad04;
	int            m_size;
	c_glow_object* m_definitions_other;
	int            m_current_objects;
	int            m_free_slot;
};
