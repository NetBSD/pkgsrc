$NetBSD: patch-index_mod__dom.c,v 1.1 2026/01/20 09:41:13 wiz Exp $

Add missing header for atoi().

--- index/mod_dom.c.orig	2026-01-20 09:40:21.883156021 +0000
+++ index/mod_dom.c
@@ -21,6 +21,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #include <config.h>
 #endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <assert.h>
 #include <ctype.h>
 #include <stdarg.h>
