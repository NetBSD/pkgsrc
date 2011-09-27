$NetBSD: patch-lib_getline.h,v 1.2 2011/09/27 12:43:21 ryoon Exp $

* Avoid getline conflict

--- lib/getline.h.orig	2005-04-04 20:46:05.000000000 +0000
+++ lib/getline.h
@@ -11,8 +11,10 @@
 
 #define GETLINE_NO_LIMIT -1
 
+#ifndef HAVE_GETLINE
 int
   getline __PROTO ((char **_lineptr, size_t *_n, FILE *_stream));
+#endif
 int
   getline_safe __PROTO ((char **_lineptr, size_t *_n, FILE *_stream,
                          int limit));
