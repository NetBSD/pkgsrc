$NetBSD: patch-common_putilimp.h,v 1.3 2013/10/19 08:47:36 adam Exp $

--- common/putilimp.h.orig	2013-10-04 20:49:30.000000000 +0000
+++ common/putilimp.h
@@ -128,6 +128,8 @@ typedef size_t uintptr_t;
    /* not defined */
 #elif U_PLATFORM == U_PF_IPHONE
    /* not defined */
+#elif defined(__MirBSD__)
+   /* not defined */
 #else
 #   define U_TIMEZONE timezone
 #endif
