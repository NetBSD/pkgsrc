$NetBSD: patch-common_putilimp.h,v 1.1 2012/07/10 19:14:48 bsiegert Exp $

--- common/putilimp.h.orig	Fri Jun 22 08:38:46 2012
+++ common/putilimp.h
@@ -119,6 +119,8 @@ typedef size_t uintptr_t;
 #   define U_TIMEZONE _timezone
 #elif U_PLATFORM == U_PF_OS400
    /* not defined */
+#elif defined(__MirBSD__)
+   /* not defined */
 #else
 #   define U_TIMEZONE timezone
 #endif
