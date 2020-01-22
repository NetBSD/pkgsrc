$NetBSD: patch-util.h,v 1.1 2020/01/22 18:53:13 adam Exp $

Include config.h before using HAVE_HTONLL.
https://github.com/memcached/memcached/issues/598

--- util.h.orig	2020-01-22 14:55:21.000000000 +0000
+++ util.h
@@ -20,6 +20,7 @@ bool safe_strtod(const char *str, double
 bool safe_strcpy(char *dst, const char *src, const size_t dstmax);
 bool safe_memcmp(const void *a, const void *b, size_t len);
 
+#include "config.h"
 #ifndef HAVE_HTONLL
 extern uint64_t htonll(uint64_t);
 extern uint64_t ntohll(uint64_t);
