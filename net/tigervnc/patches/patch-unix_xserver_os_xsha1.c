$NetBSD: patch-unix_xserver_os_xsha1.c,v 1.1 2026/09/14 21:50:24 tnn Exp $

- handle nettle 4 API change

--- unix/xserver/os/xsha1.c.orig	2026-05-24 10:08:04.017415329 +0000
+++ unix/xserver/os/xsha1.c
@@ -143,7 +143,7 @@ x_sha1_final(void *ctx, unsigned char re
 
 #elif defined(HAVE_SHA1_IN_LIBNETTLE)   /* Use libnettle for SHA1 */
 
-#include <nettle/sha.h>
+#include <nettle/sha1.h>
 
 void *
 x_sha1_init(void)
@@ -166,7 +166,7 @@ x_sha1_update(void *ctx, void *data, int
 int
 x_sha1_final(void *ctx, unsigned char result[20])
 {
-    sha1_digest(ctx, 20, result);
+    sha1_digest(ctx, result);
     free(ctx);
     return 1;
 }
