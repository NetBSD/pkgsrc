$NetBSD: patch-mainloop.c,v 1.2 2013/01/18 00:34:30 mef Exp $

Fix unused attribute usage.

--- mainloop.c.orig	2013-01-15 16:21:14.000000000 +0000
+++ mainloop.c
@@ -86,7 +86,7 @@ static const char *fix_mcwd(char *ans)
 }
 
 int unix_dir_loop(Stream_t *Stream, MainParam_t *mp); 
-int unix_loop(UNUSED(Stream_t *Stream), MainParam_t *mp, char *arg,
+int unix_loop(Stream_t *Stream UNUSEDP, MainParam_t *mp, char *arg,
 	      int follow_dir_link);
 
 static int _unix_loop(Stream_t *Dir, MainParam_t *mp,
@@ -95,7 +95,7 @@ static int _unix_loop(Stream_t *Dir, Mai
 	return unix_dir_loop(Dir, mp);
 }
 
-int unix_loop(UNUSED(Stream_t *Stream), MainParam_t *mp,
+int unix_loop(Stream_t *Stream, MainParam_t *mp,
 	      char *arg, int follow_dir_link)
 {
 	int ret;
