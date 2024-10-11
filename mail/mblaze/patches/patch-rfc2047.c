$NetBSD: patch-rfc2047.c,v 1.1 2024/10/11 06:37:20 nia Exp $

Compatibility with non-POSIX iconv.

--- rfc2047.c.orig	2024-10-11 06:32:35.457280198 +0000
+++ rfc2047.c
@@ -8,6 +8,13 @@
 #include "blaze822.h"
 #include "blaze822_priv.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#endif
+#endif
+
 // XXX keep trying bytewise on invalid iconv
 
 int
@@ -232,7 +239,11 @@ blaze822_decode_rfc2047(char *dst, char 
 		}
 
 		decchunk = dec;
+#if !defined(NETBSD_POSIX_ICONV) || defined(__sun)
+		ssize_t r = iconv(ic, (const char **)&dec, &declen, &dst, &dlen);
+#else
 		ssize_t r = iconv(ic, &dec, &declen, &dst, &dlen);
+#endif
 		if (r < 0) {
 			if (errno == E2BIG) {
 				break;
