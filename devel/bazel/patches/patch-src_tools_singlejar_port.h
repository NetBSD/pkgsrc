$NetBSD: patch-src_tools_singlejar_port.h,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- src/tools/singlejar/port.h.orig	2023-11-29 01:53:34.029841579 +0000
+++ src/tools/singlejar/port.h
@@ -32,7 +32,7 @@
 typedef off_t off64_t;
 #elif defined(_WIN32)
 typedef __int64 off64_t;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 typedef int64_t off64_t;
 #endif
 static_assert(sizeof(off64_t) == 8, "File offset type must be 64-bit");
