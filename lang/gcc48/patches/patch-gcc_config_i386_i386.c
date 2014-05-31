$NetBSD: patch-gcc_config_i386_i386.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/config/i386/i386.c.orig	2014-05-08 19:32:34.000000000 +0000
+++ gcc/config/i386/i386.c
@@ -2265,6 +2265,8 @@ struct ix86_frame
   HOST_WIDE_INT reg_save_offset;
   HOST_WIDE_INT sse_reg_save_offset;
 
+  HOST_WIDE_INT local_size;
+
   /* When save_regs_using_mov is set, emit prologue using
      move instead of push instructions.  */
   bool save_regs_using_mov;
@@ -8941,6 +8943,7 @@ ix86_compute_frame_layout (struct ix86_f
   HOST_WIDE_INT size = get_frame_size ();
   HOST_WIDE_INT to_allocate;
 
+  frame->local_size = size;
   frame->nregs = ix86_nsaved_regs ();
   frame->nsseregs = ix86_nsaved_sseregs ();
 
@@ -10293,6 +10296,9 @@ ix86_expand_prologue (void)
       m->fs.realigned = true;
     }
 
+  if (warn_stack_larger_than && frame.local_size > stack_larger_than_size)
+    warning (OPT_Wstack_larger_than_, "stack usage is %ld bytes", frame.local_size);
+
   int_registers_saved = (frame.nregs == 0);
   sse_registers_saved = (frame.nsseregs == 0);
 
