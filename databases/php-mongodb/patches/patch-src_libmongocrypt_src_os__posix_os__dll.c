$NetBSD: patch-src_libmongocrypt_src_os__posix_os__dll.c,v 1.1 2024/02/28 16:22:25 taca Exp $

Add support for NetBSD.

--- src/libmongocrypt/src/os_posix/os_dll.c.orig	2024-02-25 06:40:43.615857808 +0000
+++ src/libmongocrypt/src/os_posix/os_dll.c
@@ -95,7 +95,7 @@ mcr_dll_path_result mcr_dll_path(mcr_dll
     return (mcr_dll_path_result){.error_string = mstr_copy_cstr("Handle not found in loaded modules")};
 }
 
-#elif defined(__linux__) || defined(__FreeBSD__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <link.h>
 
