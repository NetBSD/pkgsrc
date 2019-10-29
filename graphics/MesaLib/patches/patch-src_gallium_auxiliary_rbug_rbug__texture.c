$NetBSD: patch-src_gallium_auxiliary_rbug_rbug__texture.c,v 1.1 2019/10/29 20:20:04 nia Exp $

Needs alloca definition.

--- src/gallium/auxiliary/rbug/rbug_texture.c.orig	2019-10-24 16:13:03.000000000 +0000
+++ src/gallium/auxiliary/rbug/rbug_texture.c
@@ -36,6 +36,7 @@
 
 #include "rbug_internal.h"
 #include "rbug_texture.h"
+#include "c99_alloca.h"
 
 int rbug_send_texture_list(struct rbug_connection *__con,
                            uint32_t *__serial)
