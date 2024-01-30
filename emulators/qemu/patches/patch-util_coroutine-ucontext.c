$NetBSD: patch-util_coroutine-ucontext.c,v 1.2 2024/01/30 18:20:09 adam Exp $

https://github.com/omniosorg/omnios-extra/blob/master/build/qemu/patches/0008-Temporary-coroutine-patch-pending-illumos-15206.patch

--- util/coroutine-ucontext.c.orig	2024-01-29 19:13:22.000000000 +0000
+++ util/coroutine-ucontext.c
@@ -320,6 +320,12 @@ qemu_coroutine_switch(Coroutine *from_,
 
     ret = sigsetjmp(from->env, 0);
     if (ret == 0) {
+#if defined(__sun)
+#define SIGJMP2UCONTEXT(x) ((ucontext_t *)P2ROUNDUP((uintptr_t)(x),  sizeof (upad128_t)))
+        ucontext_t *f = SIGJMP2UCONTEXT(from->env);
+        ucontext_t *t = SIGJMP2UCONTEXT(to->env);
+        t->uc_mcontext.gregs[REG_FSBASE] = f->uc_mcontext.gregs[REG_FSBASE];
+#endif
         start_switch_fiber_asan(IS_ENABLED(CONFIG_COROUTINE_POOL) ||
                                 action != COROUTINE_TERMINATE ?
                                     &fake_stack_save : NULL,
