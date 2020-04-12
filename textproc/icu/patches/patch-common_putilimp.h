$NetBSD: patch-common_putilimp.h,v 1.5 2020/04/12 07:06:43 adam Exp $

MirBSD support.

--- common/putilimp.h.orig	2020-03-11 18:16:11.000000000 +0000
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
