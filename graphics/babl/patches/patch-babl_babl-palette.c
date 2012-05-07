$NetBSD: patch-babl_babl-palette.c,v 1.1 2012/05/07 08:33:27 adam Exp $

Include standard limits.h instead of values.h

--- babl/babl-palette.c.orig	2012-05-07 07:29:12.000000000 +0000
+++ babl/babl-palette.c
@@ -19,7 +19,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 #include <assert.h>
 #include "config.h"
 #include "babl-internal.h"
