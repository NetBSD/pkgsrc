$NetBSD: patch-src_xmlquery.c,v 1.1 2026/01/06 15:50:28 ryoon Exp $

* Include stdlib.h for atoi(3).

--- src/xmlquery.c.orig	2026-01-03 09:09:23.925305274 +0000
+++ src/xmlquery.c
@@ -10,6 +10,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 
