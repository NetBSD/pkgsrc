$NetBSD: patch-rtunes_parse.y,v 1.1 2015/01/09 14:26:07 joerg Exp $

--- rtunes/parse.y.orig	2015-01-09 12:52:39.000000000 +0000
+++ rtunes/parse.y
@@ -20,6 +20,7 @@
 #include <err.h>
 #include <stdarg.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <syslog.h>
 
 extern FILE	*yyin;
