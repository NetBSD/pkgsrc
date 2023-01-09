$NetBSD: patch-lib_path-concat.c,v 1.2 2023/01/09 23:29:25 sekiya Exp $

Portability fix.

--- lib/path-concat.c.orig	2012-03-23 17:50:24.184967000 +0000
+++ lib/path-concat.c
@@ -21,7 +21,7 @@
 # include <config.h>
 #endif
 
-#ifndef HAVE_MEMPCPY
+#if !defined(HAVE_MEMPCPY) && !defined(__DragonFly__)
 # define mempcpy(D, S, N) ((void *) ((char *) memcpy (D, S, N) + (N)))
 #endif
 
