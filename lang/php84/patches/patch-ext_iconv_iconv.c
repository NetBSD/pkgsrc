$NetBSD: patch-ext_iconv_iconv.c,v 1.1 2025/10/07 14:42:20 wiz Exp $

Adapt for iconv(3) change in NetBSD 10.
https://github.com/php/php-src/issues/20089

--- ext/iconv/iconv.c.orig	2025-09-23 14:14:32.000000000 +0000
+++ ext/iconv/iconv.c
@@ -44,6 +44,10 @@
 #endif
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 1000000000)
 // unfortunately, netbsd has still the old non posix conformant signature
 // libiconv tends to match the eventual system's iconv too.
 #define ICONV_CONST const
