$NetBSD: patch-runtime_src_kmp__os.h,v 1.2 2024/07/06 15:45:09 adam Exp $

NetBSD support.

--- runtime/src/kmp_os.h.orig	2024-04-17 00:21:15.000000000 +0000
+++ runtime/src/kmp_os.h
@@ -218,7 +218,7 @@ typedef kmp_uint32 kmp_uint;
 
 // stdarg handling
 #if (KMP_ARCH_ARM || KMP_ARCH_X86_64 || KMP_ARCH_AARCH64 || KMP_ARCH_WASM) &&  \
-    (KMP_OS_FREEBSD || KMP_OS_LINUX || KMP_OS_WASI)
+    (KMP_OS_FREEBSD || KMP_OS_LINUX || KMP_OS_WASI || KMP_OS_NETBSD)
 typedef va_list *kmp_va_list;
 #define kmp_va_deref(ap) (*(ap))
 #define kmp_va_addr_of(ap) (&(ap))
