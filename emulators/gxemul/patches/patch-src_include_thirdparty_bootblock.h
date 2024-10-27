$NetBSD: patch-src_include_thirdparty_bootblock.h,v 1.1 2024/10/27 20:01:43 jakllsch Exp $

--- src/include/thirdparty/bootblock.h.orig	2024-10-27 19:48:30.289666200 +0000
+++ src/include/thirdparty/bootblock.h
@@ -121,17 +121,6 @@
 #ifndef _SYS_BOOTBLOCK_H
 #define	_SYS_BOOTBLOCK_H
 
-#ifdef __attribute__
-#undef __attribute__
-#endif
-
-#ifdef __noreturn__
-#undef __noreturn__
-#endif
-
-#define __attribute__(x)  /*  */
-#define __noreturn__  /*  */
-
 #if !defined(__ASSEMBLER__)
 #if defined(_KERNEL) || defined(_STANDALONE)
 #include <sys/stdint.h>
