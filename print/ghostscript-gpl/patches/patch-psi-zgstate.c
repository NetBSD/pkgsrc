$NetBSD: patch-psi-zgstate.c,v 1.1 2026/01/03 03:50:17 dholland Exp $

Don't do illegal things with function pointer.

--- psi/zgstate.c~	2012-08-08 08:01:36.000000000 +0000
+++ psi/zgstate.c
@@ -71,6 +71,17 @@ zcurrent_bool(i_ctx_t *i_ctx_p, bool (*c
 }
 
 static int
+zset_int(i_ctx_t *i_ctx_p, void (*set_proc)(gs_state *, int))
+{
+    os_ptr op = osp;
+
+    check_type(*op, t_integer);
+    set_proc(igs, op->value.intval);
+    pop(1);
+    return 0;
+}
+
+static int
 zset_uint(i_ctx_t *i_ctx_p, void (*set_proc)(gs_state *, uint))
 {
     os_ptr op = osp;
@@ -82,6 +93,16 @@ zset_uint(i_ctx_t *i_ctx_p, void (*set_p
 }
 
 static int
+zcurrent_int(i_ctx_t *i_ctx_p, int (*current_proc)(const gs_state *))
+{
+    os_ptr op = osp;
+
+    push(1);
+    make_int(op, current_proc(igs));
+    return 0;
+}
+
+static int
 zcurrent_uint(i_ctx_t *i_ctx_p, uint (*current_proc)(const gs_state *))
 {
     os_ptr op = osp;
@@ -519,14 +540,14 @@ zcurrenttextrenderingmode(i_ctx_t *i_ctx
 static int
 zsethpglpathmode(i_ctx_t *i_ctx_p)
 {
-    return zset_uint(i_ctx_p, gs_sethpglpathmode);
+    return zset_int(i_ctx_p, gs_sethpglpathmode);
 }
 
 /* - .currenthpglpathmode <int> */
 static int
 zcurrenthpglpathmode(i_ctx_t *i_ctx_p)
 {
-    return zcurrent_uint(i_ctx_p, gs_currenthpglpathmode);
+    return zcurrent_int(i_ctx_p, gs_currenthpglpathmode);
 }
 
 /* ------ Initialization procedure ------ */
