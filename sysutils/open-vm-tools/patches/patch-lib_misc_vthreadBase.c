$NetBSD: patch-lib_misc_vthreadBase.c,v 1.1 2018/01/01 06:56:01 ryoon Exp $

--- lib/misc/vthreadBase.c.orig	2017-12-15 19:09:51.000000000 +0000
+++ lib/misc/vthreadBase.c
@@ -352,6 +352,8 @@ VThreadBase_GetKernelID(void)
 #  endif
    // Best effort until FreeBSD header update
    return (uint64)(uintptr_t)(void *)pthread_self();
+#elif defined(__NetBSD__)
+   return (uint64)(uintptr_t)(void *)pthread_self();
 #else
 #  error "Unknown platform"
 #endif
