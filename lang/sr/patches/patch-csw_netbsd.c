$NetBSD: patch-csw_netbsd.c,v 1.1 2018/04/18 08:42:16 he Exp $

Implement context switching for NetBSD.

--- csw/netbsd.c.orig	2018-04-18 07:36:39.000000000 +0000
+++ csw/netbsd.c
@@ -0,0 +1,99 @@
+/*
+ *  netbsd.c -- context switch code for NetBSD 2.
+ *
+ *  Some Makefile changes are needed to use this code.
+ */
+
+#include <ucontext.h>
+
+void sr_stk_underflow(void);
+void sr_stk_corrupted(void);
+
+static void startup(void (*)(void), unsigned long, unsigned long, unsigned long, unsigned long);
+
+static void sr_setcontext_u(ucontext_t *);
+static void sr_swapcontext_u(ucontext_t *, ucontext_t *);
+
+static void
+sr_setcontext_u(ucontext_t *uc) {
+	setcontext(uc);
+}
+
+static void
+sr_swapcontext_u(ucontext_t *oldc, ucontext_t *newc) {
+	swapcontext(oldc, newc);
+}
+
+
+/*
+ *  sr_build_context (func, buf, bufsize, arg1, arg2, arg3, arg4)
+ *
+ *  Build a context that will call func(arg1,arg2,arg3,arg4) when activated
+ *  and will catch an underflow error if func returns.  We use an intermediary
+ *  in order to catch that return.
+ */
+void
+sr_build_context (func, buf, bufsize, arg1, arg2, arg3, arg4)
+void (*func)();
+char *buf;
+int bufsize;
+unsigned long arg1, arg2, arg3, arg4;
+{
+    ucontext_t *uc = (ucontext_t *) buf;	/* put header at front of buf */
+
+    if (0 != getcontext(uc)) {			/* initialize context */
+	sr_stk_corrupted();
+    }
+
+    uc->uc_stack.ss_sp = buf + sizeof (ucontext_t);
+    uc->uc_stack.ss_size = bufsize - sizeof (ucontext_t);
+
+    makecontext (uc, startup, 5, func, arg1, arg2, arg3, arg4);
+    uc->uc_stack.ss_flags = 0;
+}
+
+/*
+ *  startup (func, a,b,c,d) -- intermediary for startup and underflow detection.
+ */
+static void
+startup (func, arg1, arg2, arg3, arg4)
+void (*func)();
+unsigned long arg1, arg2, arg3, arg4;
+{
+    (*func) (arg1, arg2, arg3, arg4);
+    sr_stk_underflow();
+}
+
+
+
+/*
+ *  sr_chg_context (newctx, oldctx) -- change contexts.
+ */
+void
+sr_chg_context (new, old)
+char *new, *old;
+{
+    ucontext_t *oldu, *newu;
+    newu = (ucontext_t *)new;
+
+    if (old) {
+	oldu = (ucontext_t *)old;
+	swapcontext(oldu, newu);
+    } else {
+	setcontext(newu);
+    }
+}
+
+
+
+/*
+ *  sr_check_stk (stk) -- check for stack overflow.
+ *
+ *  We have no idea of how to do that, so we do nothing.
+ */
+void
+sr_check_stk(stk)
+char *stk;
+{
+    /* nothing */
+}
