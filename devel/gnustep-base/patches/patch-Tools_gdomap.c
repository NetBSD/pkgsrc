$NetBSD: patch-Tools_gdomap.c,v 1.1 2015/12/29 23:09:35 bsiegert Exp $

Fix for CVE-2014-2980.
http://svn.gna.org/viewcvs/gnustep/libs/base/trunk/Tools/gdomap.c?view=patch&r1=37756&r2=37755&pathrev=37756

--- Tools/gdomap.c.orig	2011-10-25 08:02:38.000000000 +0000
+++ Tools/gdomap.c
@@ -279,7 +279,7 @@ static char	ebuf[2048];
 
 #if	defined(HAVE_SYSLOG)
 
-static int	log_priority;
+static int	log_priority = 0;
 
 static void
 gdomap_log (int prio)
@@ -4422,16 +4422,7 @@ main(int argc, char** argv)
   const char	*machine = 0;
   const char	*lookupf = 0;
   int		donamesf = 0;
-
-#if	defined(HAVE_SYSLOG)
-  /* Initially, gdomap_log errors to stderr as well as to syslogd. */
-#if	defined(SYSLOG_4_2)
-  openlog ("gdomap", LOG_NDELAY);
-  log_priority = LOG_DAEMON;
-#else
-  openlog ("gdomap", LOG_NDELAY, LOG_DAEMON);
-#endif
-#endif
+  int           forked = 0;
 
 #if	defined(__MINGW__)
   WORD wVersionRequested;
@@ -4783,7 +4774,6 @@ printf(
 #else
   if (nofork == 0)
     {
-      is_daemon = 1;
       /*
        *	Now fork off child process to run in background.
        */
@@ -4797,6 +4787,7 @@ printf(
 	    /*
 	     *	Try to run in background.
 	     */
+	    forked = 1;
 #if	defined(NeXT)
 	    setpgrp(0, getpid());
 #else
@@ -4856,6 +4847,19 @@ printf(
 
 #endif /* !__MINGW__ */
 
+  if (forked)
+    {
+      is_daemon = 1;
+#if	defined(HAVE_SYSLOG)
+#if	defined(SYSLOG_4_2)
+      openlog ("gdomap", LOG_NDELAY);
+      log_priority = LOG_DAEMON;
+#elif !defined(HAVE_SLOGF)
+      openlog ("gdomap", LOG_NDELAY, LOG_DAEMON);
+#endif
+#endif
+    }
+
   init_my_port();	/* Determine port to listen on.		*/
   init_ports();		/* Create ports to handle requests.	*/
 
