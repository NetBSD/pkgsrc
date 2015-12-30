$NetBSD: patch-eval.c,v 1.1 2015/12/30 14:59:42 taca Exp $

--- eval.c.orig	2015-11-20 00:17:25.000000000 +0000
+++ eval.c
@@ -788,7 +788,7 @@ rb_rescue2(VALUE (* b_proc) (ANYARGS), V
 {
     int state;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     volatile VALUE result = Qfalse;
     volatile VALUE e_info = th->errinfo;
     va_list args;
@@ -854,7 +854,7 @@ rb_protect(VALUE (* proc) (VALUE), VALUE
     volatile VALUE result = Qnil;
     volatile int status;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t * volatile cfp = th->cfp;
     struct rb_vm_protect_tag protect_tag;
     rb_jmpbuf_t org_jmpbuf;
 
