$NetBSD: patch-liblrzip.c,v 1.2 2017/04/05 17:34:39 adam Exp $

fmemopen() is also not available on SunOS.

--- liblrzip.c.orig	2013-09-01 14:41:11.000000000 +0000
+++ liblrzip.c
@@ -36,7 +36,7 @@
 #include "lrzip_core.h"
 #include "rzip.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun)
 # define fmemopen(s, len, modes) fake_fmemopen((s), (len), (modes))
 static FILE *fake_fmemopen(void *buf, size_t buflen, const char *mode)
 {
