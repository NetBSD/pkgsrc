$NetBSD: patch-screen.c,v 1.1 2025/02/07 03:15:06 ryoon Exp $

Use standard headers.

--- screen.c.orig	2017-07-10 19:26:25.000000000 +0000
+++ screen.c	2017-07-18 22:40:56.000000000 +0000
@@ -95,6 +95,8 @@
 # include <langinfo.h>
 #endif
 
+#include <limits.h>
+
 #include "screen.h"
 #ifdef HAVE_BRAILLE
 # include "braille.h"
