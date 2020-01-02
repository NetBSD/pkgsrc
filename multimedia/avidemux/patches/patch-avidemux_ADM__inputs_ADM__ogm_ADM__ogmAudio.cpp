$NetBSD: patch-avidemux_ADM__inputs_ADM__ogm_ADM__ogmAudio.cpp,v 1.1 2020/01/02 19:47:04 rhialto Exp $

gcc7: error: call of overloaded 'abs(__uint64_t)' is ambiguous
Fortunately since f<=val, val-f will be positive.

--- avidemux/ADM_inputs/ADM_ogm/ADM_ogmAudio.cpp.orig	2008-06-24 19:46:05.000000000 +0000
+++ avidemux/ADM_inputs/ADM_ogm/ADM_ogmAudio.cpp
@@ -402,7 +402,7 @@ static WAVHeader hdr;
 			// Now we forward till the next header is > value
 			while(_demuxer->readHeaderOfType(_currentTrack->audioTrack,&cursize,&flags,&f))
 			{
-				if(f>val || abs(f-val)<CLOSE_ENOUGH)
+				if(f>val || (val-f)<CLOSE_ENOUGH)
 				{
 					aprintf("Wanted %llu",val);
 					aprintf(" got %llu\n",f);					
