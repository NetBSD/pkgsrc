$NetBSD: patch-src_tracks_instrument__track.cpp,v 1.1 2012/07/03 18:19:53 joerg Exp $

--- src/tracks/instrument_track.cpp.orig	2012-07-03 15:40:56.000000000 +0000
+++ src/tracks/instrument_track.cpp
@@ -946,7 +946,7 @@ bool FASTCALL instrumentTrack::play( con
 		// get all notes from the given pattern...
 		noteVector & notes = p->notes();
 		// ...and set our index to zero
-		noteVector::iterator it = notes.begin();
+		noteVector::iterator it2 = notes.begin();
 
 		// very effective algorithm for playing notes that are
 		// posated within the current sample-frame
@@ -955,23 +955,23 @@ bool FASTCALL instrumentTrack::play( con
 		if( cur_start > 0 )
 		{
 			// skip notes which are posated before start-tact
-			while( it != notes.end() && ( *it )->pos() < cur_start )
+			while( it2 != notes.end() && ( *it2 )->pos() < cur_start )
 			{
-				++it;
+				++it2;
 			}
 		}
 
 		// skip notes before sample-frame
-		while( it != notes.end() &&
-			( *it )->pos( cur_start ).frames( frames_per_tact ) <
+		while( it2 != notes.end() &&
+			( *it2 )->pos( cur_start ).frames( frames_per_tact ) <
 								_start_frame )
 		{
-			++it;
+			++it2;
 		}
 
 		note * cur_note;
-		while( it != notes.end() &&
-			( ( cur_note = *it )->pos( cur_start ).frames(
+		while( it2 != notes.end() &&
+			( ( cur_note = *it2 )->pos( cur_start ).frames(
 					frames_per_tact ) ) <= end_frame )
 		{
 			if( cur_note->length() != 0 )
@@ -1024,7 +1024,7 @@ bool FASTCALL instrumentTrack::play( con
 				}
 				played_a_note = TRUE;
 			}
-			++it;
+			++it2;
 		}
 	}
 	return( played_a_note );
