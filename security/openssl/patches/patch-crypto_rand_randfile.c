$NetBSD: patch-crypto_rand_randfile.c,v 1.1 2016/09/08 15:43:13 jperkin Exp $

Support SunOS in C99 mode.

--- crypto/rand/randfile.c.orig	2016-05-03 13:44:42.000000000 +0000
+++ crypto/rand/randfile.c
@@ -58,8 +58,10 @@
 
 /* We need to define this to get macros like S_IFBLK and S_IFCHR */
 #if !defined(OPENSSL_SYS_VXWORKS)
+#if !(defined(__sun) && (__STDC_VERSION__ - 0 >= 199901L))
 # define _XOPEN_SOURCE 500
 #endif
+#endif
 
 #include <errno.h>
 #include <stdio.h>
