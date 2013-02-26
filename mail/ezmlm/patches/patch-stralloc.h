$NetBSD: patch-stralloc.h,v 1.1 2013/02/26 11:26:03 joerg Exp $

--- stralloc.h.orig	2013-02-25 16:49:07.000000000 +0000
+++ stralloc.h
@@ -1,6 +1,9 @@
 #ifndef STRALLOC_H
 #define STRALLOC_H
 
+#include <stdlib.h>
+#include <unistd.h>
+
 #include "gen_alloc.h"
 
 GEN_ALLOC_typedef(stralloc,char,s,len,a)
