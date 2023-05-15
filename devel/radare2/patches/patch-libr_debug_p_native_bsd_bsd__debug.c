$NetBSD: patch-libr_debug_p_native_bsd_bsd__debug.c,v 1.1 2023/05/15 19:05:33 he Exp $

Not all archs have PT_SETDBREGS, so conditionalize.

--- ./libr/debug/p/native/bsd/bsd_debug.c.orig	2023-01-23 10:53:42.000000000 +0000
+++ ./libr/debug/p/native/bsd/bsd_debug.c
@@ -112,8 +112,10 @@ int bsd_reg_write(RDebug *dbg, int type,
 			break;
 		case R_REG_TYPE_DRX:
 #if __KFBSD__ || __NetBSD__
+#ifdef PT_SETDBREGS
 			r = ptrace (PT_SETDBREGS, dbg->pid, (caddr_t)buf, sizeof (struct dbreg));
 #endif
+#endif
 			break;
 		case R_REG_TYPE_FPU:
 			r = ptrace (PT_SETFPREGS, dbg->pid, (caddr_t)buf, sizeof (struct fpreg));
