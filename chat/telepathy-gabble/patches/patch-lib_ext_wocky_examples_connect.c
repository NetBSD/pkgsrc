$NetBSD: patch-lib_ext_wocky_examples_connect.c,v 1.1 2012/02/16 15:50:16 hans Exp $

--- lib/ext/wocky/examples/connect.c.orig	2011-02-16 16:40:58.000000000 +0100
+++ lib/ext/wocky/examples/connect.c	2012-01-25 13:43:46.192213342 +0100
@@ -2,6 +2,7 @@
 #include <stdlib.h>
 
 #include <string.h>
+#include <strings.h>
 
 #include <glib.h>
 
