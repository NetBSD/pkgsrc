$NetBSD: patch-main.c,v 1.1 2018/05/06 17:45:30 gavan Exp $

--- main.c.orig	2016-06-30 19:23:33.000000000 +0000
+++ main.c
@@ -280,6 +280,9 @@ int runprogram( int argc, char *argv[] )
 	setsid();
         // This line makes the ptty our controlling tty. We do not otherwise need it open
         slavept=open(name, O_RDWR );
+        if ( ioctl(slavept, TIOCSCTTY, NULL) ) {
+                perror("sshpass: Failed to recover the controlling tty");
+        }
         close( slavept );
 	
 	close( masterpt );
