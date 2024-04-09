$NetBSD: patch-lib_misc_vthreadBase.c,v 1.2 2024/04/09 01:12:36 pho Exp $

NetBSD implementation for VThreadBase_GetKernelID(). Use pthread_self() and
cast the resulting pthread_t into uint64.

--- lib/misc/vthreadBase.c.orig	2024-02-06 15:08:41.000000000 +0000
+++ lib/misc/vthreadBase.c
@@ -352,6 +352,8 @@ VThreadBase_GetKernelID(void)
 #  endif
    // Best effort until FreeBSD header update
    return (uint64)(uintptr_t)(void *)pthread_self();
+#elif defined __NetBSD__
+   return (uint64)(uintptr_t)(void *)pthread_self();
 #elif defined __EMSCRIPTEN__
    return (uint64)(uintptr_t)(void *)pthread_self();
 #else
