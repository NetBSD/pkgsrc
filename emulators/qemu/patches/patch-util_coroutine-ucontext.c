$NetBSD: patch-util_coroutine-ucontext.c,v 1.1 2023/03/15 11:49:20 jperkin Exp $

https://github.com/omniosorg/omnios-extra/blob/master/build/qemu/patches/0008-Temporary-coroutine-patch-pending-illumos-15206.patch

--- util/coroutine-ucontext.c.orig	2022-12-14 16:28:45.000000000 +0000
+++ util/coroutine-ucontext.c
@@ -305,6 +305,12 @@ qemu_coroutine_switch(Coroutine *from_,
 
     ret = sigsetjmp(from->env, 0);
     if (ret == 0) {
+#if defined(__sun)
+#define SIGJMP2UCONTEXT(x) ((ucontext_t *)P2ROUNDUP((uintptr_t)(x),  sizeof (upad128_t)))
+        ucontext_t *f = SIGJMP2UCONTEXT(from->env);
+        ucontext_t *t = SIGJMP2UCONTEXT(to->env);
+        t->uc_mcontext.gregs[REG_FSBASE] = f->uc_mcontext.gregs[REG_FSBASE];
+#endif
         start_switch_fiber_asan(action, &fake_stack_save, to->stack,
                                 to->stack_size);
         start_switch_fiber_tsan(&fake_stack_save,
