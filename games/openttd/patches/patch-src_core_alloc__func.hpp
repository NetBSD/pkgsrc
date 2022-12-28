$NetBSD: patch-src_core_alloc__func.hpp,v 1.3 2022/12/28 10:13:30 nia Exp $

Need alloca.h to use alloca on SunOS.

--- src/core/alloc_func.hpp.orig	2022-04-02 10:38:20.000000000 +0000
+++ src/core/alloc_func.hpp
@@ -10,6 +10,10 @@
 #ifndef ALLOC_FUNC_HPP
 #define ALLOC_FUNC_HPP
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 /*
  * Functions to exit badly with an error message.
  * It has to be linked so the error messages are not
