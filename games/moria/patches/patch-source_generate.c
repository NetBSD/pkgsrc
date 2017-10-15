$NetBSD: patch-source_generate.c,v 1.1 2017/10/15 03:16:07 maya Exp $

Always use memset over bzero.
As opposed to implicitly declaring bzero, and because memset is a
part of the C standard.

--- source/generate.c.orig	1994-07-22 01:47:23.000000000 +0000
+++ source/generate.c
@@ -123,9 +123,6 @@ int *rdir, *cdir;
 /* Blanks out entire cave				-RAK-	*/
 static void blank_cave()
 {
-#ifndef USG
-  bzero ((char *)&cave[0][0], sizeof (cave));
-#else
 #ifdef MAC
   /* On the mac, cave is a pointer, so sizeof(cave) = 4! */
   (void)memset((char *)&cave[0][0], 0,
@@ -133,7 +130,6 @@ static void blank_cave()
 #else
   (void)memset((char *)&cave[0][0], 0, sizeof (cave));
 #endif
-#endif
 }
 
 
