$NetBSD: patch-Wnn_jutil_wnnstat.c,v 1.1 2026/07/10 23:32:38 tsutsui Exp $

- Remove unnecessary old style function declarations

--- Wnn/jutil/wnnstat.c.orig	2015-05-09 23:42:04.000000000 +0000
+++ Wnn/jutil/wnnstat.c
@@ -79,14 +79,7 @@ struct wnn_ret_buf rb = { 0, NULL };
 
 extern int optind;
 extern char *optarg;
-extern char *getenv ();
 
-#ifdef JAPANESE
-extern int eujis_to_jis8 (), eujis_to_sjis ();
-#endif
-#ifdef CHINESE
-extern int ecns_to_big5 ();
-#endif
 static void  err (), usage (), dic (), dic_all (), file_all ();
 static void printall FRWNN_PARAMS((WNN_ENV_INFO *, int));
 static void printpat FRWNN_PARAMS((WNN_ENV_INFO *, int));
@@ -129,7 +122,6 @@ main (argc, argv)
 */
   char *server_env = NULL;
   char *prog = argv[0];
-  extern char *get_server_env ();
 
 /*
     if ((p = getenv("LANG")) != NULL) {
