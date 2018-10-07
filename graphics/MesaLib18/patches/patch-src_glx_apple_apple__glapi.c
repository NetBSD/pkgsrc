$NetBSD: patch-src_glx_apple_apple__glapi.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

https://bugs.freedesktop.org/show_bug.cgi?id=90311
See also hacks.mk.

--- src/glx/apple/apple_glapi.c.orig	2018-02-09 02:17:59.000000000 +0000
+++ src/glx/apple/apple_glapi.c
@@ -39,6 +39,7 @@
 #include <GL/gl.h>
 
 #include "main/glheader.h"
+#include "main/remap.h"
 #include "glapi.h"
 #include "glapitable.h"
 
@@ -53,6 +54,8 @@ static void _apple_glapi_create_table(vo
     if (__applegl_api)
         return;
 
+    _mesa_init_remap_table(); 
+
     __ogl_framework_api = _glapi_create_table_from_handle(apple_cgl_get_dl_handle(), "gl");
     assert(__ogl_framework_api);
 
