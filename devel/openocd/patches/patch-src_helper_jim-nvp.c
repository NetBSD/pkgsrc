$NetBSD: patch-src_helper_jim-nvp.c,v 1.1 2025/04/06 10:07:06 adam Exp $

Fix build.

--- src/helper/jim-nvp.c.orig	2025-04-06 05:56:28.632419321 +0000
+++ src/helper/jim-nvp.c
@@ -21,6 +21,7 @@
 #endif
 
 #include "jim-nvp.h"
+#include <stdio.h>
 #include <string.h>
 
 int jim_get_nvp(Jim_Interp *interp,
