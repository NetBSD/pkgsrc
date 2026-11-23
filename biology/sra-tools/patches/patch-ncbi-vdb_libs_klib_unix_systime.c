$NetBSD: patch-ncbi-vdb_libs_klib_unix_systime.c,v 1.1 2026/11/23 08:07:34 wiz Exp $

Fix build on NetBSD.

--- ncbi-vdb/libs/klib/unix/systime.c.orig	2026-11-23 08:04:07.925755705 +0000
+++ ncbi-vdb/libs/klib/unix/systime.c
@@ -24,11 +24,13 @@
 *
 */
 
+#ifdef __linux__
 #define _XOPEN_SOURCE /* strptime */
 
 #if _POSIX_C_SOURCE < 199309L && ! defined __FreeBSD__
 #define _POSIX_C_SOURCE 199309L
 #endif
+#endif
 
 #include <klib/extern.h>
 #include <klib/time.h>
@@ -265,7 +267,7 @@ LIB_EXPORT rc_t CC KSleepMs(uint32_t milliseconds) {
 
     time.tv_sec = (milliseconds / 1000);
     time.tv_nsec = (milliseconds % 1000) * 1000 * 1000;
-#if _POSIX_C_SOURCE >= 199309L || defined __FreeBSD__
+#if _POSIX_C_SOURCE >= 199309L || defined __FreeBSD__ || defined(__NetBSD__)
     if ( nanosleep ( & time, NULL ) != 0 )
 #else
     #error "nanosleep is not guaranteed here"
