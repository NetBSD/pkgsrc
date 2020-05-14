$NetBSD: patch-src_rpsl_List.hh,v 1.1 2020/05/14 19:15:41 joerg Exp $

--- src/rpsl/List.hh.orig	2020-05-13 14:16:21.649149765 +0000
+++ src/rpsl/List.hh
@@ -52,10 +52,7 @@
 #ifndef LIST_H
 #define LIST_H
 
-#include <cstdio>      // For NULL definition
-#ifdef _STDDEF_H_      // for fbsd: to workaround problem with _G_config.h
-#undef _STDDEF_H_
-#endif
+#include <cstddef>      // For NULL definition
 #include <assert.h>
 
 // These list manipulation routines assume that each object that
