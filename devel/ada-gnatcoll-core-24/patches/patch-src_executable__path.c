$NetBSD: patch-src_executable__path.c,v 1.1 2025/07/10 12:35:22 dkazankov Exp $

Add NetBSD support

--- src/executable_path.c.orig	2024-09-24 12:28:32.000000000 +0300
+++ src/executable_path.c
@@ -50,7 +50,7 @@
     return (int) GetModuleFileNameA(NULL, buffer, (DWORD) size);
 }
 
-#elif defined (__linux__)
+#elif defined (__linux__) || defined (__NetBSD__)
 /* Linux implementation */
 #include <unistd.h>
 int
