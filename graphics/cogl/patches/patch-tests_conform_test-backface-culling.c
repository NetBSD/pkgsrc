$NetBSD: patch-tests_conform_test-backface-culling.c,v 1.1 2017/09/08 22:28:15 kamil Exp $

--- tests/conform/test-backface-culling.c.orig	2015-04-29 16:27:56.000000000 +0000
+++ tests/conform/test-backface-culling.c
@@ -164,7 +164,7 @@ validate_result (CoglFramebuffer *frameb
 
   for (draw_num = 0; draw_num < 16; draw_num++)
     {
-      CoglBool cull_front, cull_back;
+      CoglBool cull_front = FALSE, cull_back = FALSE;
       CoglPipelineCullFaceMode cull_mode;
 
       if (USE_LEGACY_STATE (draw_num))
@@ -308,4 +308,3 @@ test_backface_culling (void)
   if (cogl_test_verbose ())
     g_print ("OK\n");
 }
-
