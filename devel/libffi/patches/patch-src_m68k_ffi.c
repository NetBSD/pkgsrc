$NetBSD: patch-src_m68k_ffi.c,v 1.1 2020/02/26 19:15:44 adam Exp $

NetBSD/m68k support.

--- src/m68k/ffi.c.orig	2014-11-08 12:47:24.000000000 +0000
+++ src/m68k/ffi.c
@@ -9,8 +9,11 @@
 
 #include <stdlib.h>
 #include <unistd.h>
-#ifdef __rtems__
+#if defined(__rtems__)
 void rtems_cache_flush_multiple_data_lines( const void *, size_t );
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <m68k/sync_icache.h>
 #else
 #include <sys/syscall.h>
 #ifdef __MINT__
@@ -345,8 +348,10 @@ ffi_prep_closure_loc (ffi_closure* closu
   else
     *(void **)(closure->tramp + 8) = ffi_closure_SYSV;
 
-#ifdef __rtems__
+#if defined(__rtems__)
   rtems_cache_flush_multiple_data_lines( codeloc, FFI_TRAMPOLINE_SIZE );
+#elif defined(__NetBSD__)
+  m68k_sync_icache(codeloc, FFI_TRAMPOLINE_SIZE);
 #elif defined(__MINT__)
   Ssystem(S_FLUSHCACHE, codeloc, FFI_TRAMPOLINE_SIZE);
 #else
