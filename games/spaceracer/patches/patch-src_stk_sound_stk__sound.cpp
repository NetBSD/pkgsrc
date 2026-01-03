$NetBSD: patch-src_stk_sound_stk__sound.cpp,v 1.1 2026/01/03 10:52:03 wiz Exp $

g++ does not like double definition of default parameters.

--- src/stk/sound/stk_sound.cpp.orig	2001-07-15 23:26:19.000000000 +0200
+++ src/stk/sound/stk_sound.cpp	2006-03-09 14:59:42.000000000 +0100
@@ -145,7 +145,7 @@ void Stk_CSound::Play(char *filename)
 
 
 /* Server class */
-Stk_PSound::Stk_PSound(int freq=25)
+Stk_PSound::Stk_PSound(int freq)
         :Stk2_Looper(freq)
 {
         // no last sing
