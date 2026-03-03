$NetBSD: patch-source_fitz_stext-search.c,v 1.1 2026/03/03 21:49:01 yhardy Exp $

Since we are dynamically linking libmujs from lang/mujs, we should
use the regexp.h header file from the mujs package.

--- source/fitz/stext-search.c.orig	2026-03-02 10:51:00.197237036 +0000
+++ source/fitz/stext-search.c
@@ -22,7 +22,7 @@
 
 #include "mupdf/fitz.h"
 
-#include "../thirdparty/mujs/regexp.h"
+#include "mujs/regexp.h"
 
 #include "mupdf/ucdn.h"
 
