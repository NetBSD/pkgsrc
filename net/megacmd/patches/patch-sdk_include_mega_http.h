$NetBSD: patch-sdk_include_mega_http.h,v 1.1 2024/06/18 18:23:15 bsiegert Exp $

Add support to other BSDs.
Upstream pull req: https://github.com/meganz/sdk/pull/2662

--- sdk/include/mega/http.h.orig	2024-05-17 14:19:43.000000000 +0000
+++ sdk/include/mega/http.h
@@ -42,7 +42,7 @@
 #pragma warning(pop)
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <netinet/in.h>
 #endif
 
