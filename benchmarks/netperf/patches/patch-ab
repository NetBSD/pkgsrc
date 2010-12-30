$NetBSD: patch-ab,v 1.3 2010/12/30 08:05:18 obache Exp $

* sendfile(2) of DragonFly is FreeBSD in origin. 

--- src/nettest_bsd.c.orig	2009-06-04 00:31:15.000000000 +0000
+++ src/nettest_bsd.c
@@ -4372,7 +4372,7 @@ Size (bytes)\n\
       sv.sfv_off = send_ring->offset;
       sv.sfv_len =  send_ring->length;
       if ((len = sendfilev(send_socket, &sv, 1, &scratch_len)) != send_size)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 	/* so close to HP-UX and yet so far away... :) */
 	if ((sendfile(send_ring->fildes, 
 		      send_socket, 
