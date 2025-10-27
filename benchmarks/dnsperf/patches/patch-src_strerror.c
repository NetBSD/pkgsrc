$NetBSD: patch-src_strerror.c,v 1.1 2025/10/27 18:23:49 tron Exp $

Fix build problem under NetBSD

--- src/strerror.c.orig	2024-01-18 12:43:29.000000000 +0000
+++ src/strerror.c	2025-10-27 18:17:35.197811762 +0000
@@ -26,7 +26,7 @@
 
 const char* perf_strerror_r(int errnum, char* str, size_t len)
 {
-#if ((_POSIX_C_SOURCE >= 200112L) && !_GNU_SOURCE) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if ((_POSIX_C_SOURCE >= 200112L) && !_GNU_SOURCE) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
     if (strerror_r(errnum, str, len)) {
         (void)snprintf(str, len, "Error %d", errnum);
     }
