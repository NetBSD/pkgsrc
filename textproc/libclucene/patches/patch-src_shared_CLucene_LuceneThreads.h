$NetBSD: patch-src_shared_CLucene_LuceneThreads.h,v 1.1 2014/04/15 20:31:11 asau Exp $

pthread.h is needed on FreeBSD.

--- src/shared/CLucene/LuceneThreads.h.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/shared/CLucene/LuceneThreads.h
@@ -7,6 +7,9 @@
 #ifndef _LuceneThreads_h
 #define  _LuceneThreads_h
 
+#if defined(_CL_HAVE_PTHREAD)
+#include <pthread.h>
+#endif
 
 CL_NS_DEF(util)
 class CLuceneThreadIdCompare;
