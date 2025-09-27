$NetBSD: patch-put.c,v 1.1 2025/09/27 12:07:21 tnn Exp $

- add missing includes

--- put.c.orig	2025-09-27 11:55:41.259298501 +0000
+++ put.c
@@ -14,7 +14,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
-/*#include <ctype.h>*/
+#include <ctype.h>
 #include "config.h"
 
 #include "skey.h"
