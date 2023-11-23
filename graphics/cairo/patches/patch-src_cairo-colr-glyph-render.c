$NetBSD: patch-src_cairo-colr-glyph-render.c,v 1.1 2023/11/23 10:57:44 jperkin Exp $

SunOS needs alloca.h.

--- src/cairo-colr-glyph-render.c.orig	2023-11-23 10:39:05.280692069 +0000
+++ src/cairo-colr-glyph-render.c
@@ -38,6 +38,9 @@
 #include "cairo-path-private.h"
 #include "cairo-pattern-private.h"
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <assert.h>
 #include <math.h>
 #include <stdio.h>
