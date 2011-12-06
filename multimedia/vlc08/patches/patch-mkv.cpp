$NetBSD: patch-mkv.cpp,v 1.1 2011/12/06 22:02:24 sborrill Exp $

--- modules/demux/mkv.cpp.orig	2011-12-06 21:42:19.000000000 +0000
+++ modules/demux/mkv.cpp	2011-12-06 21:43:41.000000000 +0000
@@ -75,7 +75,6 @@
 #include "matroska/KaxSegment.h"
 #include "matroska/KaxTag.h"
 #include "matroska/KaxTags.h"
-#include "matroska/KaxTagMulti.h"
 #include "matroska/KaxTracks.h"
 #include "matroska/KaxTrackAudio.h"
 #include "matroska/KaxTrackVideo.h"
@@ -3871,74 +3870,6 @@
                     }
                     ep->Up();
                 }
-                else if( MKV_IS_ID( el, KaxTagGeneral ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + General" );
-                    ep->Down();
-                    while( ( el = ep->Get() ) != NULL )
-                    {
-                        msg_Dbg( &sys.demuxer, "|   |   + Unknown (%s)", typeid( *el ).name() );
-                    }
-                    ep->Up();
-                }
-                else if( MKV_IS_ID( el, KaxTagGenres ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Genres" );
-                    ep->Down();
-                    while( ( el = ep->Get() ) != NULL )
-                    {
-                        msg_Dbg( &sys.demuxer, "|   |   + Unknown (%s)", typeid( *el ).name() );
-                    }
-                    ep->Up();
-                }
-                else if( MKV_IS_ID( el, KaxTagAudioSpecific ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Audio Specific" );
-                    ep->Down();
-                    while( ( el = ep->Get() ) != NULL )
-                    {
-                        msg_Dbg( &sys.demuxer, "|   |   + Unknown (%s)", typeid( *el ).name() );
-                    }
-                    ep->Up();
-                }
-                else if( MKV_IS_ID( el, KaxTagImageSpecific ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Images Specific" );
-                    ep->Down();
-                    while( ( el = ep->Get() ) != NULL )
-                    {
-                        msg_Dbg( &sys.demuxer, "|   |   + Unknown (%s)", typeid( *el ).name() );
-                    }
-                    ep->Up();
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiComment ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Comment" );
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiCommercial ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Commercial" );
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiDate ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Date" );
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiEntity ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Entity" );
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiIdentifier ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Identifier" );
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiLegal ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Legal" );
-                }
-                else if( MKV_IS_ID( el, KaxTagMultiTitle ) )
-                {
-                    msg_Dbg( &sys.demuxer, "|   + Multi Title" );
-                }
                 else
                 {
                     msg_Dbg( &sys.demuxer, "|   + Unknown (%s)", typeid( *el ).name() );
