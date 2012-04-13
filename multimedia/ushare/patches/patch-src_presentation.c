$NetBSD: patch-src_presentation.c,v 1.1 2012/04/13 23:44:39 obache Exp $

* some header files are not included by libupnp>=1.6.7.

--- src/presentation.c.orig	2007-12-09 13:03:36.000000000 +0000
+++ src/presentation.c
@@ -19,6 +19,8 @@
  */
 
 #include <stdlib.h>
+#include <string.h>
+#include <stdio.h>
 
 #if HAVE_LANGINFO_CODESET
 # include <langinfo.h>
