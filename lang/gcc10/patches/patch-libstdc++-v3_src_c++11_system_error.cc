$NetBSD: patch-libstdc++-v3_src_c++11_system_error.cc,v 1.1 2024/04/01 14:33:58 js Exp $

EALREADY and EBUSY are the same on QNX.

--- libstdc++-v3/src/c++11/system_error.cc.orig	2023-07-07 07:08:22.000000000 +0000
+++ libstdc++-v3/src/c++11/system_error.cc
@@ -100,7 +100,7 @@ namespace
 #ifdef EAGAIN
       case EAGAIN:
 #endif
-#ifdef EALREADY
+#if defined(EALREADY) && (!defined(EBUSY) || EALREADY != EBUSY)
       case EALREADY:
 #endif
 #ifdef EBADF
