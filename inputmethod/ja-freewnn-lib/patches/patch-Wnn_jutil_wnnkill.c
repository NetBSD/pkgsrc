$NetBSD: patch-Wnn_jutil_wnnkill.c,v 1.1 2026/07/10 23:32:38 tsutsui Exp $

- Remove unnecessary old style function declarations

--- Wnn/jutil/wnnkill.c.orig	2015-05-09 23:42:04.000000000 +0000
+++ Wnn/jutil/wnnkill.c
@@ -88,7 +88,6 @@ main (int argc, char** argv)
   static char lang[64] = { 0 };
   char *server_env = NULL;
   char *prog = argv[0];
-  extern char *_wnn_get_machine_of_serv_defs (), *get_server_env ();
 
 /*
   char* p;
@@ -215,13 +214,6 @@ main (int argc, char** argv)
   exit (0);
 }
 
-#ifdef JAPANESE
-extern int eujis_to_jis8 (), eujis_to_sjis ();
-#endif
-#ifdef CHINESE
-extern int ecns_to_big5 ();
-#endif
-
 static void
 out (const char* format, ...)
 {
