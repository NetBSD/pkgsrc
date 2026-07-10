$NetBSD: patch-Wnn_jlib_js.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Remove unnecessary old stype declarations for standard C functions
- Add a proper arg for a signal handler function

--- Wnn/jlib/js.c.orig	2015-05-09 23:42:04.000000000 +0000
+++ Wnn/jlib/js.c
@@ -130,7 +130,7 @@ static int rbc = -1;                    
 # endif /* defined(EWOULDBLOCK) */
 #endif /* defined(EAGAIN) */
 
-static void connect_timeout ();
+static void connect_timeout FRWNN_PARAMS((int));
 static int _get_server_name FRWNN_PARAMS((const char *, char *));
 static int writen FRWNN_PARAMS((int));
 static char *get_unixdomain_of_serv_defs FRWNN_PARAMS((const char *lang));
@@ -395,8 +395,10 @@ cd_open_in (server, lang, timeout)
 }
 
 static void
-connect_timeout ()
+connect_timeout (sig)
+     int sig;
 {
+  (void) sig;
 }
 
 /* get server name and return serverNo */
@@ -726,7 +728,6 @@ dmp (p, c)
 static char *
 getlogname ()
 {
-  struct passwd *getpwuid ();
   return getpwuid (getuid ())->pw_name;
 }
 
@@ -906,7 +907,6 @@ js_set_lang (env, lang)
      register char *lang;
 {
   register char *p;
-  extern char *getenv ();
 
   /* if not specified language , use $LANG */
   if (lang == 0 || *lang == 0)
