$NetBSD: patch-main.c,v 1.1 2013/05/23 15:01:05 christos Exp $
Replace event_gotsig and event_sigcb with proper signal access

--- main.c.orig	2008-09-27 16:35:43.000000000 -0400
+++ main.c	2013-05-23 10:58:29.000000000 -0400
@@ -40,13 +40,11 @@
 #define MESSAGE "hash check"
 #define METER "|/-\\"
 
-static void sighandler(int);
+static void addhandler(int);
 void usage(void);
 
 extern char *optarg;
 extern int  optind;
-extern int event_gotsig;
-extern int (*event_sigcb)(void);
 
 void
 usage(void)
@@ -56,9 +54,14 @@
 }
 
 static void
-sighandler(int sig)
+addhandler(int sig)
 {
-	event_gotsig = 1;
+	struct event sig_ev;
+	int got;
+
+	evsignal_set(&sig_ev, sig,
+	    (void (*)(evutil_socket_t, short, void *))terminate_handler, &got);
+	evsignal_add(&sig_ev, NULL);
 }
 
 int
@@ -76,10 +79,10 @@
 	GC_INIT();
 	#endif
 
-	signal(SIGHUP, sighandler);
-	signal(SIGABRT, sighandler);
-	signal(SIGINT, sighandler);
-	signal(SIGQUIT, sighandler);
+	addhandler(SIGHUP);
+	addhandler(SIGABRT);
+	addhandler(SIGINT);
+	addhandler(SIGQUIT);
 	/* don't die on sigpipe */
 	signal(SIGPIPE, SIG_IGN);
 	#if defined(__SVR4) && defined(__sun)
@@ -160,7 +163,7 @@
 
 	srandom(time(NULL));
 	network_init();
-	event_sigcb = terminate_handler;
+
 	network_start_torrent(torrent, rlp.rlim_cur);
 
 	exit(0);
