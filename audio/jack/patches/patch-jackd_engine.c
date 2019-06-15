$NetBSD: patch-jackd_engine.c,v 1.1 2019/06/15 08:21:33 adam Exp $

BSD poll returns POLLIN, not POLLHUP, when the socket is closed,
as does Darwin.

--- jackd/engine.c.orig	2016-09-14 17:41:53.000000000 +0000
+++ jackd/engine.c
@@ -1435,7 +1435,7 @@ handle_external_client_request (jack_eng
 	if ((r = read (client->request_fd, &req, sizeof(req)))
 	    < (ssize_t)sizeof(req)) {
 		if (r == 0) {
-#if defined(JACK_USE_MACH_THREADS) || defined(__OpenBSD__)
+#if defined(JACK_HOST_HAS_BSD_POLL) || defined(JACK_USE_MACH_THREADS)
 			/* poll is implemented using
 			   select (see the macosx/fakepoll
 			   code). When the socket is closed
