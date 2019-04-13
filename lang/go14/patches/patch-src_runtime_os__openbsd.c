$NetBSD: patch-src_runtime_os__openbsd.c,v 1.1 2019/04/13 23:09:40 maya Exp $
$OpenBSD: patch-src_runtime_os_openbsd_c,v 1.1 2018/04/05 17:47:30 jsing Exp $

OpenBSD 6.4 needs stack pages to be mapped with MAP_STACK.

Index: src/runtime/os_openbsd.c
--- src/runtime/os_openbsd.c.orig
+++ src/runtime/os_openbsd.c
@@ -167,7 +167,7 @@ runtime·newosproc(M *mp, void *stk)
 
 	param.tf_tcb = (byte*)&mp->tls[0];
 	param.tf_tid = (int32*)&mp->procid;
-	param.tf_stack = stk;
+	param.tf_stack = (void*)((uintptr)stk - 8);
 
 	oset = runtime·sigprocmask(SIG_SETMASK, sigset_all);
 	ret = runtime·tfork(&param, sizeof(param), mp, mp->g0, runtime·mstart);
