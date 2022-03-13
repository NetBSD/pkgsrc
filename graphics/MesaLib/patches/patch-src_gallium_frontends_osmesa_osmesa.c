$NetBSD: patch-src_gallium_frontends_osmesa_osmesa.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

atexit() is not a good idea in shared libraries.

--- src/gallium/frontends/osmesa/osmesa.c.orig	2021-07-14 20:04:55.420007000 +0000
+++ src/gallium/frontends/osmesa/osmesa.c
@@ -134,7 +134,11 @@ osmesa_st_get_param(struct st_manager *s
 static struct st_manager *stmgr = NULL;
 static struct st_api *stapi = NULL;
 
+#if defined(HAVE_NOATEXIT)
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 destroy_st_manager(void)
 {
    if (stmgr) {
@@ -151,8 +155,10 @@ destroy_st_manager(void)
 static void
 create_st_manager(void)
 {
+#if !defined(HAVE_NOATEXIT)
    if (atexit(destroy_st_manager) != 0)
       return;
+#endif
 
    stmgr = CALLOC_STRUCT(st_manager);
    if (stmgr) {
