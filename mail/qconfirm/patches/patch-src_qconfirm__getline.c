$NetBSD: patch-src_qconfirm__getline.c,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm_getline.c.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm_getline.c
@@ -2,7 +2,7 @@
 #include "stralloc.h"
 #include "byte.h"
 
-int getline(buffer *b, stralloc *line) {
+int qconfirm_getline(buffer *b, stralloc *line) {
   int r, i;
   char *x;
 
