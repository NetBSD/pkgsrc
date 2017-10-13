$NetBSD: patch-control.c,v 1.3 2017/10/13 17:24:05 christos Exp $

Remove static from inline; each inlined copy might have its own buffer and
this is not want you want if you define it static. In this case it does not
matter, since it is only 4K and we don't return it, so don't try to play
around with saving stack space for no good reason.

--- control.c.orig	2017-08-02 13:46:06.000000000 -0400
+++ control.c	2017-10-13 12:46:33.920249976 -0400
@@ -1600,7 +1600,7 @@
     int x;
     unsigned char e;
     int err;
-    static unsigned char wbuf[MAX_RECV_SIZE];
+    unsigned char wbuf[MAX_RECV_SIZE];
     int pos = 0;
 
     if (c->fd < 0)
