$NetBSD: patch-rtunes_parse.y,v 1.3 2021/03/30 12:01:04 nia Exp $

Merge fixes from https://github.com/erincandescent/rtunes

--- rtunes/parse.y.orig	2009-06-27 10:10:32.000000000 +0000
+++ rtunes/parse.y
@@ -27,9 +27,13 @@
 #include <stdarg.h>
 #include <stdint.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
-
+#ifdef __linux__
+#include <bsd/stdlib.h>
+#endif
+	
 FILE	*fin;
 int	lineno = 1;
 int	errors = 0;
