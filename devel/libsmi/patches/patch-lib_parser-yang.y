$NetBSD: patch-lib_parser-yang.y,v 1.1 2024/08/05 08:19:59 tnn Exp $

Add missing prototypes.

--- lib/parser-yang.y.orig	2014-10-11 15:58:53.000000000 +0000
+++ lib/parser-yang.y
@@ -35,6 +35,8 @@
 #endif
 
 #include "yang.h"
+#include "yang-check.h"
+#include "smi-check.h"
 #include "yang-data.h"
 #include "parser-yang.h"
 #include "scanner-yang.h"
