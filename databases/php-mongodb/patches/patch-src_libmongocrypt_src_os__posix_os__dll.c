$NetBSD: patch-src_libmongocrypt_src_os__posix_os__dll.c,v 1.2 2025/01/13 16:42:20 taca Exp $

Add support for NetBSD.

--- src/libmongocrypt/src/os_posix/os_dll.c.orig	2024-11-27 14:34:48.000000000 +0000
+++ src/libmongocrypt/src/os_posix/os_dll.c
@@ -99,7 +99,7 @@ bool mcr_dll_path_supported(void) {
     return true;
 }
 
-#elif defined(__linux__) || defined(__FreeBSD__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <link.h>
 
