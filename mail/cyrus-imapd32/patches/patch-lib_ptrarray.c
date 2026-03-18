$NetBSD: patch-lib_ptrarray.c,v 1.1 2026/03/18 18:01:35 nia Exp $

Fix implicit declaration of string functions.

--- lib/ptrarray.c.orig	2026-03-18 17:32:07.783214958 +0000
+++ lib/ptrarray.c
@@ -45,6 +45,7 @@
 
 #include "ptrarray.h"
 #include <memory.h>
+#include <string.h>
 #include "xmalloc.h"
 
 EXPORTED ptrarray_t *ptrarray_new(void)
