$NetBSD: patch-lib_nettle_rnd.c,v 1.1 2013/11/29 22:55:29 wiz Exp $

http://lists.gnupg.org/pipermail/gnutls-devel/2013-November/006588.html

--- lib/nettle/rnd.c.orig	2013-11-10 17:59:14.000000000 +0000
+++ lib/nettle/rnd.c
@@ -90,8 +90,7 @@ static int do_trivia_source(int init)
 	memcpy(&event.now, &current_time, sizeof(event.now));
 #ifdef HAVE_GETRUSAGE
 	if (getrusage(RUSAGE_SELF, &event.rusage) < 0) {
-		_gnutls_debug_log("getrusage failed: %s\n",
-				  strerror(errno));
+		_gnutls_debug_log("getrusage failed\n");
 		abort();
 	}
 #endif
@@ -244,8 +243,7 @@ static int do_device_source_urandom(int 
 			if (res <= 0) {
 				if (res < 0) {
 					_gnutls_debug_log
-					    ("Failed to read /dev/urandom: %s\n",
-					     strerror(errno));
+					    ("Failed to read /dev/urandom\n");
 				} else {
 					_gnutls_debug_log
 					    ("Failed to read /dev/urandom: end of file\n");
