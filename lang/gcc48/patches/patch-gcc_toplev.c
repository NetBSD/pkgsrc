$NetBSD: patch-gcc_toplev.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/toplev.c.orig	2013-03-28 08:29:51.000000000 +0000
+++ gcc/toplev.c
@@ -1519,6 +1519,8 @@ process_options (void)
 
   /* Targets must be able to place spill slots at lower addresses.  If the
      target already uses a soft frame pointer, the transition is trivial.  */
+  if (flag_stack_protect == -1)
+    flag_stack_protect = FRAME_GROWS_DOWNWARD ? 1 : 0;
   if (!FRAME_GROWS_DOWNWARD && flag_stack_protect)
     {
       warning (0, "-fstack-protector not supported for this target");
