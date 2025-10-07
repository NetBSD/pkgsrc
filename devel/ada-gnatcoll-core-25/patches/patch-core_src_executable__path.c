$NetBSD: patch-core_src_executable__path.c,v 1.2 2025/10/07 20:45:10 dkazankov Exp $

Add NetBSD support

--- core/src/executable_path.c.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/executable_path.c
@@ -50,7 +50,7 @@
     return (int) GetModuleFileNameA(NULL, buffer, (DWORD) size);
 }
 
-#elif defined (__linux__)
+#elif defined (__linux__) || defined (__unix__)
 /* Linux implementation */
 #include <unistd.h>
 int
