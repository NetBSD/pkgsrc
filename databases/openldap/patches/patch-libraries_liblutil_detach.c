$NetBSD: patch-libraries_liblutil_detach.c,v 1.1 2011/03/25 10:37:19 adam Exp $

--- libraries/liblutil/detach.c.orig	2011-03-25 10:28:19.000000000 +0000
+++ libraries/liblutil/detach.c
@@ -128,7 +128,7 @@ lutil_detach( int debug, int do_close )
 
 #ifdef HAVE_SETSID
 		(void) setsid();
-#elif TIOCNOTTY
+#elif defined(TIOCNOTTY)
 		if ( (sd = open( "/dev/tty", O_RDWR )) != -1 ) {
 			(void) ioctl( sd, TIOCNOTTY, NULL );
 			(void) close( sd );
