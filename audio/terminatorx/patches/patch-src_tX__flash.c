$NetBSD: patch-src_tX__flash.c,v 1.1 2019/10/05 12:09:26 nia Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_flash.c.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/tX_flash.c
@@ -27,7 +27,7 @@
 #include "tX_flash.h"
 #include "tX_types.h"
 #include "tX_global.h"
-#include <malloc.h>
+#include <stdlib.h>
 
 #ifndef WIN32
 #include <unistd.h>
