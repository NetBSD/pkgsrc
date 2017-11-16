$NetBSD: patch-plugins_filter.c,v 1.1 2017/11/16 15:05:31 khorben Exp $

Mark the constructor and destructor functions as such.

--- plugins/filter.c.orig	2002-07-06 17:22:01.000000000 +0000
+++ plugins/filter.c
@@ -252,7 +252,8 @@ LADSPA_Descriptor * g_psHPFDescriptor = 
 
 /* _init() is called automatically when the plugin library is first
    loaded. */
-void 
+static void _init() __attribute__((constructor));
+static void 
 _init() {
 
   char ** pcPortNames;
@@ -431,7 +432,8 @@ deleteDescriptor(LADSPA_Descriptor * psD
 /*****************************************************************************/
 
 /* _fini() is called automatically when the library is unloaded. */
-void
+static void _fini() __attribute__((destructor));
+static void
 _fini() {
   deleteDescriptor(g_psLPFDescriptor);
   deleteDescriptor(g_psHPFDescriptor);
