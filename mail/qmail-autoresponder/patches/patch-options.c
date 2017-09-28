$NetBSD: patch-options.c,v 1.1 2017/09/28 17:27:34 schmonz Exp $

Remove unneeded include.

--- options.c.orig	2017-08-22 23:38:24.000000000 +0000
+++ options.c
@@ -1,5 +1,4 @@
 #define _XOPEN_SOURCE
-#include <mysql/mysql.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
