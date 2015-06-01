$NetBSD: patch-lib_nettle_rnd-common.c,v 1.1 2015/06/01 21:50:22 spz Exp $

http://lists.gnupg.org/pipermail/gnutls-devel/2013-November/006588.html

--- lib/nettle/rnd-common.c.orig	2015-03-23 07:19:23.000000000 +0000
+++ lib/nettle/rnd-common.c
@@ -61,8 +61,7 @@ void _rnd_get_event(struct event_st *e)
 
 #ifdef HAVE_GETRUSAGE
 	if (getrusage(ARG_RUSAGE, &e->rusage) < 0) {
-		_gnutls_debug_log("getrusage failed: %s\n",
-			  strerror(errno));
+		_gnutls_debug_log("getrusage failed\n");
 	}
 #endif
 
@@ -153,8 +152,7 @@ static int _rnd_get_system_entropy_urand
 		if (res <= 0) {
 			if (res < 0) {
 				_gnutls_debug_log
-					("Failed to read /dev/urandom: %s\n",
-					 strerror(errno));
+					("Failed to read /dev/urandom\n");
 			} else {
 				_gnutls_debug_log
 					("Failed to read /dev/urandom: end of file\n");
