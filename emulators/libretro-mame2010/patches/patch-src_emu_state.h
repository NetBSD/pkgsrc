$NetBSD: patch-src_emu_state.h,v 1.1 2020/05/14 19:35:59 joerg Exp $

--- src/emu/state.h.orig	2020-05-13 15:02:59.769613659 +0000
+++ src/emu/state.h
@@ -18,16 +18,8 @@
 #ifndef __STATE_H__
 #define __STATE_H__
 
-#if defined(__MACH__) && !defined(IOS)
 #include <type_traits>
 #define DEF_NAMESPACE std
-#elif defined(IOS)
-#include <tr1/type_traits>
-#define DEF_NAMESPACE std::tr1
-#elif defined(__GNUC__)
-#include <tr1/type_traits>
-#define DEF_NAMESPACE std::tr1
-#endif
 
 
 /***************************************************************************
