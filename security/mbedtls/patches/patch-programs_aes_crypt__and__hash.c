$NetBSD: patch-programs_aes_crypt__and__hash.c,v 1.1 2020/06/02 15:07:59 nia Exp $

Not actually so harmless on SunOS, which requires at least 200112L
when compiling c99.

--- programs/aes/crypt_and_hash.c.orig	2020-04-09 13:12:23.000000000 +0000
+++ programs/aes/crypt_and_hash.c
@@ -23,7 +23,7 @@
 /* Enable definition of fileno() even when compiling with -std=c99. Must be
  * set before config.h, which pulls in glibc's features.h indirectly.
  * Harmless on other platforms. */
-#define _POSIX_C_SOURCE 1
+#define _POSIX_C_SOURCE 200112L
 
 #if !defined(MBEDTLS_CONFIG_FILE)
 #include "mbedtls/config.h"
