$NetBSD: patch-common_putilimp.h,v 1.4 2013/11/05 15:25:37 ryoon Exp $

* GCC for arm does not have __sync_add_and_fetch() etc.

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
@@ -187,7 +189,7 @@ typedef size_t uintptr_t;
     /* Use the predefined value. */
 #elif U_PLATFORM == U_PF_MINGW
     #define U_HAVE_GCC_ATOMICS 0
-#elif U_GCC_MAJOR_MINOR >= 404 || defined(__clang__)
+#elif (U_GCC_MAJOR_MINOR >= 404 && !defined(__arm__)) || defined(__clang__)
     /* TODO: Intel icc and IBM xlc on AIX also support gcc atomics.  (Intel originated them.)
      *       Add them for these compilers.
      * Note: Clang sets __GNUC__ defines for version 4.2, so misses the 4.4 test here.
