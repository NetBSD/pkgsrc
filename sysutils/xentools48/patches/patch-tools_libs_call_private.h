$NetBSD: patch-tools_libs_call_private.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libs/call/private.h.orig	2017-03-28 10:42:37.000000000 +0200
+++ tools/libs/call/private.h	2017-03-28 10:43:04.000000000 +0200
@@ -11,8 +11,10 @@
 #ifndef PAGE_SHIFT /* Mini-os, Yukk */
 #define PAGE_SHIFT           12
 #endif
-#ifndef __MINIOS__ /* Yukk */
+#ifndef PAGE_SIZE
 #define PAGE_SIZE            (1UL << PAGE_SHIFT)
+#endif
+#ifndef PAGE_MASK
 #define PAGE_MASK            (~(PAGE_SIZE-1))
 #endif
 
