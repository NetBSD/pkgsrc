$NetBSD: patch-cipher_rijndael-arm.S,v 1.1 2016/07/02 13:24:17 wiz Exp $

Fix ARM unaligned access problem.
https://lists.gnupg.org/pipermail/gcrypt-devel/2016-June/003904.html

--- cipher/rijndael-arm.S.orig	2016-03-23 11:59:34.000000000 +0000
+++ cipher/rijndael-arm.S
@@ -19,6 +19,7 @@
  */
 
 #include <config.h>
+#undef __ARM_FEATURE_UNALIGNED
 
 #if defined(__ARMEL__)
 #ifdef HAVE_COMPATIBLE_GCC_ARM_PLATFORM_AS
