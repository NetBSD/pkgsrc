$NetBSD: patch-concatkdf.c,v 1.1 2023/11/12 16:50:10 rillig Exp $

Fix build on NetBSD.

--- src/concatkdf.c.orig	2023-08-22 12:18:03.202602223 +0200
+++ src/concatkdf.c	2023-08-22 12:17:49.008381386 +0200
@@ -12,8 +12,12 @@
 #include <malloc.h>
 #else
 #include <arpa/inet.h>
+#ifdef __NetBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
 #endif
+#endif
 #include <openssl/evp.h>
 #include <string.h>
 #include <cjose/base64.h>
