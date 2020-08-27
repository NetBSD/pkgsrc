$NetBSD: patch-tools_libs_call_private.h,v 1.2 2020/08/27 08:22:33 bouyer Exp $

--- tools/libs/call/private.h.orig	2020-05-14 14:19:32.000000000 +0200
+++ tools/libs/call/private.h	2020-05-27 14:11:18.819118697 +0200
@@ -7,13 +7,19 @@
 #include <xencall.h>
 
 #include <xen/xen.h>
+#ifdef __NetBSD__
+#include <xen/xenio.h>
+#else
 #include <xen/sys/privcmd.h>
+#endif
 
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
 
