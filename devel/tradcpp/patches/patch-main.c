$NetBSD: patch-main.c,v 1.1 2013/07/10 05:50:05 dholland Exp $

--- main.c~	2013-07-09 17:48:47.000000000 +0000
+++ main.c
@@ -29,6 +29,7 @@
 
 #include <stdbool.h>
 #include <stdio.h>
+#include <stdarg.h>
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
