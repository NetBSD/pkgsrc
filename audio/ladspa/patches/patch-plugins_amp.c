$NetBSD: patch-plugins_amp.c,v 1.1 2017/11/16 15:05:31 khorben Exp $

Mark the constructor and destructor functions as such.

--- plugins/amp.c.orig	2002-07-06 17:20:19.000000000 +0000
+++ plugins/amp.c
@@ -152,7 +152,8 @@ LADSPA_Descriptor * g_psStereoDescriptor
 
 /* _init() is called automatically when the plugin library is first
    loaded. */
-void 
+static void _init() __attribute__((constructor));
+static void 
 _init() {
 
   char ** pcPortNames;
@@ -335,7 +336,8 @@ deleteDescriptor(LADSPA_Descriptor * psD
 /*****************************************************************************/
 
 /* _fini() is called automatically when the library is unloaded. */
-void
+static void _fini() __attribute__((destructor));
+static void
 _fini() {
   deleteDescriptor(g_psMonoDescriptor);
   deleteDescriptor(g_psStereoDescriptor);
