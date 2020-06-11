$NetBSD: patch-programs_aes_aescrypt2.c,v 1.2 2020/06/11 11:43:50 nia Exp $

Not actually so harmless on SunOS, which requires at least 200112L
when compiling c99.

https://github.com/ARMmbed/mbedtls/pull/3421

--- programs/aes/aescrypt2.c.orig	2020-04-09 13:12:23.000000000 +0000
+++ programs/aes/aescrypt2.c
@@ -22,7 +22,7 @@
 /* Enable definition of fileno() even when compiling with -std=c99. Must be
  * set before config.h, which pulls in glibc's features.h indirectly.
  * Harmless on other platforms. */
-#define _POSIX_C_SOURCE 1
+#define _POSIX_C_SOURCE 200112L
 
 #if !defined(MBEDTLS_CONFIG_FILE)
 #include "mbedtls/config.h"
