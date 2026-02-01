$NetBSD: patch-cipher_asm-common-amd64.h,v 1.1 2026/02/01 08:51:16 wiz Exp $

https://dev.gnupg.org/file/view/35198420/

--- cipher/asm-common-amd64.h.orig	2025-05-08 06:47:34.000000000 +0000
+++ cipher/asm-common-amd64.h
@@ -53,6 +53,12 @@
 #  define ADD_RIP
 #endif
 
+#ifdef __PIC__
+#  define AT_PLT ELF(@PLT)
+#else
+#  define AT_PLT
+#endif
+
 #if defined(HAVE_COMPATIBLE_GCC_WIN64_PLATFORM_AS) || !defined(__PIC__)
 #  define GET_EXTERN_POINTER(name, reg) movabsq $name, reg
 #else
