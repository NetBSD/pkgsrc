$NetBSD: patch-c_malloc__closure.h,v 1.2 2016/11/14 14:31:18 wiz Exp $

Handle PaX/MPROTECT

--- c/malloc_closure.h.orig	2016-09-21 22:53:05.889258675 -0400
+++ c/malloc_closure.h	2016-09-21 22:53:47.057812777 -0400
@@ -57,6 +57,8 @@
 
 #define is_emutramp_enabled() (emutramp_enabled >= 0 ? emutramp_enabled \
         : (emutramp_enabled = emutramp_enabled_check ()))
+#elif defined(__NetBSD__)
+#define is_emutramp_enabled() 1	/* We have PaX MPROTECT, no point in checking if it is enabled! */
 #else
 #define is_emutramp_enabled() 0
 #endif
