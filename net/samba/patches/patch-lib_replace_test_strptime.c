$NetBSD: patch-lib_replace_test_strptime.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add string.h.

--- ../lib/replace/test/strptime.c.orig	2026-07-21 20:16:09.294482497 +0000
+++ ../lib/replace/test/strptime.c
@@ -3,6 +3,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <time.h>
 
 #define true 1
