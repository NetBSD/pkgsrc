$NetBSD: patch-lib_getline.c,v 1.2 2011/09/27 12:43:21 ryoon Exp $

* Avoid getline conflict

--- lib/getline.c.orig	2005-04-04 20:46:05.000000000 +0000
+++ lib/getline.c
@@ -154,6 +154,7 @@ getstr (lineptr, n, stream, terminator, 
   return ret;
 }
 
+#ifndef HAVE_GETLINE
 int
 getline (lineptr, n, stream)
      char **lineptr;
@@ -162,6 +163,7 @@ getline (lineptr, n, stream)
 {
   return getstr (lineptr, n, stream, '\n', 0, GETLINE_NO_LIMIT);
 }
+#endif
 
 int
 getline_safe (lineptr, n, stream, limit)
