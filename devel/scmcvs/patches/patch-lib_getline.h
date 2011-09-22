$NetBSD: patch-lib_getline.h,v 1.1 2011/09/22 15:16:26 ryoon Exp $

* Avoid getline conflict

--- lib/getline.h.orig	2005-04-04 20:46:05.000000000 +0000
+++ lib/getline.h
@@ -12,7 +12,7 @@
 #define GETLINE_NO_LIMIT -1
 
 int
-  getline __PROTO ((char **_lineptr, size_t *_n, FILE *_stream));
+  getline_cvs __PROTO ((char **_lineptr, size_t *_n, FILE *_stream));
 int
   getline_safe __PROTO ((char **_lineptr, size_t *_n, FILE *_stream,
                          int limit));
