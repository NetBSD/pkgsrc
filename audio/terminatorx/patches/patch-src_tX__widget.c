$NetBSD: patch-src_tX__widget.c,v 1.1 2019/10/05 12:09:26 nia Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_widget.c.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/tX_widget.c
@@ -28,7 +28,6 @@
 #include "tX_widget.h"
 #include "tX_types.h"
 #include "tX_global.h"
-#include <malloc.h>
 #include <stdlib.h>
 #include <string.h>
 
