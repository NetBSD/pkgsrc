$NetBSD: patch-plugins_noise.c,v 1.1 2017/11/16 15:05:31 khorben Exp $

Mark the constructor and destructor functions as such.

--- plugins/noise.c.orig	2002-07-06 17:22:34.000000000 +0000
+++ plugins/noise.c
@@ -142,7 +142,8 @@ LADSPA_Descriptor * g_psDescriptor;
 
 /* _init() is called automatically when the plugin library is first
    loaded. */
-void 
+static void _init() __attribute__((constructor));
+static void 
 _init() {
 
   char ** pcPortNames;
@@ -219,7 +220,8 @@ _init() {
 /*****************************************************************************/
 
 /* _fini() is called automatically when the library is unloaded. */
-void 
+static void _fini() __attribute__((destructor));
+static void 
 _fini() {
   long lIndex;
   if (g_psDescriptor) {
