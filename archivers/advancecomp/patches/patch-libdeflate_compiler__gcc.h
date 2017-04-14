$NetBSD: patch-libdeflate_compiler__gcc.h,v 1.1 2017/04/14 17:48:56 joerg Exp $

--- libdeflate/compiler_gcc.h.orig	2017-04-12 14:01:12.705351515 +0000
+++ libdeflate/compiler_gcc.h
@@ -3,6 +3,11 @@
  * handles clang and the Intel C Compiler.
  */
 
+#ifdef __NetBSD__
+/* Avoid conflicts due to changing the prototypes of bswap32 and co. */
+#include <sys/endian.h>
+#endif
+
 #define GCC_PREREQ(major, minor)		\
 	(__GNUC__ > (major) ||			\
 	 (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
