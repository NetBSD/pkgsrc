$NetBSD: patch-src_tX__widget.c,v 1.2 2023/11/04 10:02:57 wiz Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_widget.c.orig	2022-08-25 14:40:07.000000000 +0000
+++ src/tX_widget.c
@@ -28,7 +28,6 @@
 #include "tX_types.h"
 #include "tX_widget.h"
 #include <gtk/gtk.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <string.h>
 
