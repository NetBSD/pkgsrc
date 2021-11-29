$NetBSD: patch-src_cmark.h,v 1.1 2021/11/29 10:44:16 cirnatdan Exp $

Fix "strict" prototype
Submitted upstream: https://github.com/commonmark/cmark/pull/430

--- src/cmark.h.orig	2021-09-24 15:56:14.000000000 +0000
+++ src/cmark.h
@@ -102,7 +102,7 @@ typedef struct cmark_mem {
 
 /** Returns a pointer to the default memory allocator.
  */
-CMARK_EXPORT cmark_mem *cmark_get_default_mem_allocator();
+CMARK_EXPORT cmark_mem *cmark_get_default_mem_allocator(void);
 
 /**
  * ## Creating and Destroying Nodes
