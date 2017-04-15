$NetBSD: patch-screen.c,v 1.4 2017/04/15 22:31:49 kim Exp $

Use standard headers.

--- screen.c.orig	2017-01-17 19:28:29.000000000 +0000
+++ screen.c
@@ -88,6 +88,8 @@
 # include <langinfo.h>
 #endif
 
+#include <limits.h>
+
 #include "screen.h"
 #ifdef HAVE_BRAILLE
 # include "braille.h"
