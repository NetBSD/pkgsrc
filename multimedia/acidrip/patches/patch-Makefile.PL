$NetBSD: patch-Makefile.PL,v 1.1 2020/03/29 01:05:18 joerg Exp $

Don't care if mp3lame is supported in mencoder. LAVC can be used just as well.

--- Makefile.PL.orig	2020-03-29 00:27:46.399480924 +0000
+++ Makefile.PL
@@ -59,19 +59,13 @@ print "test for MPlayer: "; die "Not Fou
   "AcidRip is based around the MPlayer video player. it has not been found on\n" .
   "your current path. Install it from http://mplayerhq/hu see INSTALL.html or\n" .
   "INSTALL for installation instructions.\n" .
-  "***************\n\n" if ( system "mplayer 2&>1 > /dev/null" ); print "found\n";
+  "***************\n\n" if ( system "mplayer > /dev/null 2>&1" ); print "found\n";
 
 print "test for MEncoder: "; die "Not Found!\n\n***************\n" .
   "AcidRip uses MEncoder, which is part of MPlayer video player package. This\n" .
   "was not found. Install it from http://mplayerhq/hu see INSTALL.html or\n" .
   "INSTALL for installation instructions.\n" .
-  "***************\n\n" if ( system "mencoder -ovc help 2> /dev/null | grep MEncoder > /dev/null" ); print "found\n";
-
-print "test for MP3 support in mencoder: "; die "Not Found!\n\n***************\n" .
-  "MEncoder was found, however it does not have MP3 support built into it.\n" .
-  "If you DO want MP3 support you'll need to recompile mplayer with mp3 support\n" .
-  "See INSTALL or INSTALL.html for more information\n" .
-  "***************\n\n" if ( system "mencoder -oac help 2> /dev/null | grep mp3lame > /dev/null" ); print "found\n";
+  "***************\n\n" if ( system "2> /dev/null mencoder -ovc help | grep MEncoder > /dev/null" ); print "found\n";
 
 print "Everything looks good here...\n"; 
 
