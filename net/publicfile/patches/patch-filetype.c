$NetBSD: patch-filetype.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- filetype.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ filetype.c
@@ -1,5 +1,6 @@
 #include "filetype.h"
 #include "str.h"
+#include "exit.h"
 
 void filetype(char *fn,stralloc *contenttype)
 {
