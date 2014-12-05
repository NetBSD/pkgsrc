$NetBSD: patch-lib_nettle_rnd.c,v 1.4 2014/12/05 12:43:24 khorben Exp $

http://lists.gnupg.org/pipermail/gnutls-devel/2013-November/006588.html

--- lib/nettle/rnd.c.orig	2014-10-14 19:06:59.000000000 +0000
+++ lib/nettle/rnd.c
@@ -101,8 +101,7 @@ static void _rnd_get_event(struct event_
 
 #ifdef HAVE_GETRUSAGE
 	if (getrusage(ARG_RUSAGE, &e->rusage) < 0) {
-		_gnutls_debug_log("getrusage failed: %s\n",
-			  strerror(errno));
+		_gnutls_debug_log("getrusage failed\n");
 	}
 #endif
 
@@ -266,8 +265,7 @@ static int do_device_source_urandom(int 
 			if (res <= 0) {
 				if (res < 0) {
 					_gnutls_debug_log
-					    ("Failed to read /dev/urandom: %s\n",
-					     strerror(errno));
+					    ("Failed to read /dev/urandom\n");
 				} else {
 					_gnutls_debug_log
 					    ("Failed to read /dev/urandom: end of file\n");
