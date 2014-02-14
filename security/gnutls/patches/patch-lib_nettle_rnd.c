$NetBSD: patch-lib_nettle_rnd.c,v 1.2 2014/02/14 17:24:27 drochner Exp $

http://lists.gnupg.org/pipermail/gnutls-devel/2013-November/006588.html

--- lib/nettle/rnd.c.orig	2014-01-27 18:27:10.000000000 +0000
+++ lib/nettle/rnd.c
@@ -97,8 +97,7 @@ static void _rnd_get_event(struct event_
 # else
 	if (getrusage(RUSAGE_SELF, &e->rusage) < 0) {
 # endif
-		_gnutls_debug_log("getrusage failed: %s\n",
-				  strerror(errno));
+		_gnutls_debug_log("getrusage failed\n");
 		abort();
 	}
 #endif
@@ -263,8 +262,7 @@ static int do_device_source_urandom(int 
 			if (res <= 0) {
 				if (res < 0) {
 					_gnutls_debug_log
-					    ("Failed to read /dev/urandom: %s\n",
-					     strerror(errno));
+					    ("Failed to read /dev/urandom\n");
 				} else {
 					_gnutls_debug_log
 					    ("Failed to read /dev/urandom: end of file\n");
