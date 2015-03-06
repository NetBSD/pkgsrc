$NetBSD: patch-user-exec.c,v 1.5 2015/03/06 13:22:03 tnn Exp $

From 3f9744aaaeeaea9c55c814b9e7be0f8cce1fb7f9 Mon Sep 17 00:00:00 2001
From: Tobias Nygren <tnn@NetBSD.org>
To: qemu-devel@nongnu.org
Cc: Tobias Nygren <tnn@NetBSD.org>
Date: Thu, 5 Mar 2015 22:15:08 +0100
Subject: [PATCH] user-exec.c: fix build on NetBSD/sparc64 and NetBSD/arm

A couple of #ifdef changes necessary to use NetBSD's ucontext
structs on sparc64 and arm.

Signed-off-by: Tobias Nygren <tnn@NetBSD.org>
---
 user-exec.c | 16 +++++++++++++++-
 1 file changed, 15 insertions(+), 1 deletion(-)

diff --git a/user-exec.c b/user-exec.c
index 1ff8673..8f57e8a 100644
--- user-exec.c
+++ user-exec.c
@@ -404,6 +404,10 @@ int cpu_signal_handler(int host_signum, void *pinfo,
     struct sigcontext *uc = puc;
     unsigned long pc = uc->sc_pc;
     void *sigmask = (void *)(long)uc->sc_mask;
+#elif defined(__NetBSD__)
+    ucontext_t *uc = puc;
+    unsigned long pc = _UC_MACHINE_PC(uc);
+    void *sigmask = (void *)&uc->uc_sigmask;
 #endif
 #endif
 
@@ -441,15 +445,25 @@ int cpu_signal_handler(int host_signum, void *pinfo,
 
 #elif defined(__arm__)
 
+#if defined(__NetBSD__)
+#include <ucontext.h>
+#endif
+
 int cpu_signal_handler(int host_signum, void *pinfo,
                        void *puc)
 {
     siginfo_t *info = pinfo;
+#if defined(__NetBSD__)
+    ucontext_t *uc = puc;
+#else
     struct ucontext *uc = puc;
+#endif
     unsigned long pc;
     int is_write;
 
-#if defined(__GLIBC__) && (__GLIBC__ < 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ <= 3))
+#if defined(__NetBSD__)
+    pc = uc->uc_mcontext.__gregs[_REG_R15];
+#elif defined(__GLIBC__) && (__GLIBC__ < 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ <= 3))
     pc = uc->uc_mcontext.gregs[R15];
 #else
     pc = uc->uc_mcontext.arm_pc;
