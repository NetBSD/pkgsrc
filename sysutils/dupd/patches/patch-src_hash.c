$NetBSD: patch-src_hash.c,v 1.1 2025/02/26 14:03:06 hauke Exp $

Add NetBSD

--- src/hash.c.orig	2025-02-26 12:50:53.710506570 +0000
+++ src/hash.c
@@ -65,6 +65,10 @@
 #define FADVISE 1
 #endif
 
+#ifdef __NetBSD__
+#define FADVISE 1
+#endif
+
 #define MAX_BLOCK (1024 * 1024)
 
 
