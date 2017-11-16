$NetBSD: patch-plugins_delay.c,v 1.1 2017/11/16 15:05:31 khorben Exp $

Mark the constructor and destructor functions as such.

--- plugins/delay.c.orig	2002-07-06 17:21:20.000000000 +0000
+++ plugins/delay.c
@@ -228,7 +228,8 @@ LADSPA_Descriptor * g_psDescriptor = NUL
 
 /* _init() is called automatically when the plugin library is first
    loaded. */
-void 
+static void _init() __attribute__((constructor));
+static void 
 _init() {
 
   char ** pcPortNames;
@@ -322,7 +323,8 @@ _init() {
 /*****************************************************************************/
 
 /* _fini() is called automatically when the library is unloaded. */
-void 
+static void _fini() __attribute__((destructor));
+static void 
 _fini() {
   long lIndex;
   if (g_psDescriptor) {
