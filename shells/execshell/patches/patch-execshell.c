$NetBSD: patch-execshell.c,v 1.1 2025/07/16 19:35:28 schmonz Exp $

Use pkgsrc linenoise.

--- execshell.c.orig	2025-07-16 19:21:15.162568036 +0000
+++ execshell.c
@@ -16,8 +16,9 @@
 #include <execline/execline.h>
 
 #define UTF8
+#undef UTF8
 
-#include "linenoise/linenoise.h"
+#include <linenoise.h>
 #ifdef UTF8
 #include "linenoise/encodings/utf8.h"
 #endif
