$NetBSD: patch-lib_nettle_rnd.c,v 1.3 2014/12/05 12:25:42 khorben Exp $

http://lists.gnupg.org/pipermail/gnutls-devel/2013-November/006588.html

--- lib/nettle/rnd.c.orig	2014-10-11 17:43:54.000000000 +0000
+++ lib/nettle/rnd.c
@@ -104,8 +104,7 @@ static void _rnd_get_event(struct event_
 #ifdef HAVE_GETRUSAGE
 	if (rusage_arg != -1) {
 		if (getrusage(rusage_arg, &e->rusage) < 0) {
-			_gnutls_debug_log("getrusage failed: %s\n",
-				  strerror(errno));
+			_gnutls_debug_log("getrusage failed\n");
 		}
 	}
 #endif
@@ -270,8 +269,7 @@ static int do_device_source_urandom(int 
 			if (res <= 0) {
 				if (res < 0) {
 					_gnutls_debug_log
-					    ("Failed to read /dev/urandom: %s\n",
-					     strerror(errno));
+					    ("Failed to read /dev/urandom\n");
 				} else {
 					_gnutls_debug_log
 					    ("Failed to read /dev/urandom: end of file\n");
