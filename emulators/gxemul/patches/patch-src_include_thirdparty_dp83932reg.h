$NetBSD: patch-src_include_thirdparty_dp83932reg.h,v 1.1 2024/10/27 20:01:43 jakllsch Exp $

--- src/include/thirdparty/dp83932reg.h.orig	2024-10-27 19:48:53.211473370 +0000
+++ src/include/thirdparty/dp83932reg.h
@@ -4,17 +4,6 @@
 #ifndef _DEV_IC_DP83932REG_H_
 #define	_DEV_IC_DP83932REG_H_
 
-#ifdef __attribute__
-#undef __attribute__
-#endif
-
-#ifdef __noreturn__
-#undef __noreturn__
-#endif
-
-#define __attribute__(x)  /*  */
-#define __noreturn__  /*  */
-
 /*-
  * Copyright (c) 2001 The NetBSD Foundation, Inc.
  * All rights reserved.
