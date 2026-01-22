$NetBSD: patch-tf-psa-crypto_drivers_builtin_src_platform__util.c,v 1.1 2026/01/22 22:46:06 wiz Exp $

Fix build on NetBSD.

--- tf-psa-crypto/drivers/builtin/src/platform_util.c.orig	2026-01-22 22:43:49.391669440 +0000
+++ tf-psa-crypto/drivers/builtin/src/platform_util.c
@@ -11,7 +11,7 @@
  * mbedtls_config.h, which pulls in glibc's features.h. Harmless on other platforms
  * except OpenBSD, where it stops us accessing explicit_bzero.
  */
-#if !defined(_POSIX_C_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_POSIX_C_SOURCE) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #define _POSIX_C_SOURCE 200112L
 #endif
 
