$NetBSD: patch-src_buffer.c,v 1.1 2014/06/13 00:13:13 wiedi Exp $

NetBSD doesn't have alloca.h
--- src/buffer.c.orig	2014-05-18 21:52:06.000000000 +0000
+++ src/buffer.c
@@ -32,7 +32,9 @@
 #include <time.h>
 #include <errno.h>
 #include <unistd.h>
+#if !defined(__NetBSD__)
 #include <alloca.h>
+#endif
 #include <assert.h>
 #include "buffer.h"
 #include "logger.h"
