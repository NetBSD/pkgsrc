$NetBSD: patch-src_emu_state.h,v 1.2 2020/05/30 20:36:15 nia Exp $

--- src/emu/state.h.orig	2020-05-25 02:01:22.000000000 +0000
+++ src/emu/state.h
@@ -18,17 +18,8 @@
 #ifndef __STATE_H__
 #define __STATE_H__
 
-#if (defined(__MACH__) && !defined(IOS)) || defined(ANDROID)
 #include <type_traits>
 #define DEF_NAMESPACE std
-#elif defined(IOS)
-#include <type_traits>
-#define DEF_NAMESPACE std::tr1
-#define DEF_NAMESPACE std
-#elif defined(__GNUC__)
-#include <tr1/type_traits>
-#define DEF_NAMESPACE std::tr1
-#endif
 
 
 /***************************************************************************
