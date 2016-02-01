$NetBSD: patch-cow_utils.h,v 1.1 2016/02/01 02:41:21 jmmv Exp $

--- src/cow_utils.h.orig	2015-01-14 10:08:20.000000000 +0000
+++ src/cow_utils.h
@@ -8,7 +8,9 @@
 #define COW_UTILS_H
 
 #define VM_AND_BUFFER_CACHE_SYNCHRONIZED
+#if !defined(MAXBSIZE)
 #define MAXBSIZE 4096
+#endif
 
 struct cow {
 	mode_t umask;
