$NetBSD: patch-src_mesa_main_marshal.h,v 1.1 2020/01/18 21:29:05 triaxx Exp $

ALIGN is also defined in machine/param.h on FreetBSD.

--- src/mesa/main/marshal.h.orig	2019-12-04 22:10:14.000000000 +0000
+++ src/mesa/main/marshal.h
@@ -55,6 +55,9 @@ _mesa_glthread_allocate_command(struct gl_context *ctx
    struct glthread_state *glthread = ctx->GLThread;
    struct glthread_batch *next = &glthread->batches[glthread->next];
    struct marshal_cmd_base *cmd_base;
+#ifdef ALIGN
+#undef ALIGN
+#endif
    const size_t aligned_size = ALIGN(size, 8);
 
    if (unlikely(next->used + size > MARSHAL_MAX_CMD_SIZE)) {
