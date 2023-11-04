$NetBSD: patch-src_tX__flash.c,v 1.2 2023/11/04 10:02:57 wiz Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_flash.c.orig	2022-08-25 14:40:07.000000000 +0000
+++ src/tX_flash.c
@@ -26,7 +26,7 @@
 #include "tX_flash.h"
 #include "tX_global.h"
 #include "tX_types.h"
-#include <malloc.h>
+#include <stdlib.h>
 
 #ifndef WIN32
 #include <unistd.h>
