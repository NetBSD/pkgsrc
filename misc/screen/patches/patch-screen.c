$NetBSD: patch-screen.c,v 1.1 2017/01/23 17:58:34 dholland Exp $

Use standard headers.

--- screen.c~	2017-01-17 19:28:29.000000000 +0000
+++ screen.c
@@ -88,6 +88,8 @@
 # include <langinfo.h>
 #endif
 
+#include <limits.h>
+
 #include "screen.h"
 #ifdef HAVE_BRAILLE
 # include "braille.h"
