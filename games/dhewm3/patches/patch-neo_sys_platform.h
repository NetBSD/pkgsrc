$NetBSD: patch-neo_sys_platform.h,v 1.1 2020/01/25 14:38:51 jmcneill Exp $

Use __builtin_allocate on Unix

--- neo/sys/platform.h.orig	2018-12-15 04:49:59.000000000 +0000
+++ neo/sys/platform.h
@@ -136,8 +136,8 @@ If you have questions concerning this li
 // Unix
 #ifdef __unix__
 
-#define _alloca						alloca
-#define _alloca16( x )				((void *)((((uintptr_t)alloca( (x)+15 )) + 15) & ~15))
+#define _alloca						__builtin_alloca
+#define _alloca16( x )				((void *)((((uintptr_t)__builtin_alloca( (x)+15 )) + 15) & ~15))
 
 #ifdef GAME_DLL
 #define ID_GAME_API					__attribute__((visibility ("default")))
