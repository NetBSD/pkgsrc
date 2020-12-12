$NetBSD: patch-tio.c,v 1.1 2020/12/12 13:32:51 nia Exp $

Include stdarg.h for va_list.

--- tio.c.orig	2020-04-24 13:06:48.000000000 +0000
+++ tio.c
@@ -59,6 +59,7 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
+#include <stdarg.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <assert.h>
