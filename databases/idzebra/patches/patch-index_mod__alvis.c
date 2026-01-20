$NetBSD: patch-index_mod__alvis.c,v 1.1 2026/01/20 09:41:13 wiz Exp $

Add missing header for atoi().

--- index/mod_alvis.c.orig	2016-01-08 11:33:29.000000000 +0000
+++ index/mod_alvis.c
@@ -21,6 +21,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #include <config.h>
 #endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <assert.h>
 #include <ctype.h>
 
