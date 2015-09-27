$NetBSD: patch-src_sound__stuff.c,v 1.1 2015/09/27 10:07:53 tnn Exp $

Wow. Amazing that this doesn't crash for anyone else.
Reported upstream in private mail.

--- src/sound_stuff.c.orig	2011-12-26 22:41:48.000000000 +0000
+++ src/sound_stuff.c
@@ -96,7 +96,7 @@ int strsound ( char s1[] )
    int i = 0;
    char s[10];
    if(strlen(s1) > 4) {
-      strcpy(s,&s[strlen(s)-4]);
+      strcpy(s,&s1[strlen(s1)-4]);
       while (s[i]) {
          s[i] = toupper(s[i]);
          ++i;
