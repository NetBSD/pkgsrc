$NetBSD: patch-eval__error.c,v 1.1 2015/11/20 14:31:59 joerg Exp $

--- eval_error.c.orig	2015-11-16 15:02:19.000000000 +0000
+++ eval_error.c
@@ -80,9 +80,9 @@ static void
 error_print(void)
 {
     volatile VALUE errat = Qundef;
-    rb_thread_t *th = GET_THREAD();
-    VALUE errinfo = th->errinfo;
-    int raised_flag = th->raised_flag;
+    rb_thread_t * volatile th = GET_THREAD();
+    volatile VALUE errinfo = th->errinfo;
+    volatile int raised_flag = th->raised_flag;
     volatile VALUE eclass = Qundef, e = Qundef;
     const char *volatile einfo;
     volatile long elen;
