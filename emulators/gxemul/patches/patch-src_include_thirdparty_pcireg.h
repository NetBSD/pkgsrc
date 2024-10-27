$NetBSD: patch-src_include_thirdparty_pcireg.h,v 1.1 2024/10/27 20:01:43 jakllsch Exp $

--- src/include/thirdparty/pcireg.h.orig	2024-10-27 19:49:11.060880615 +0000
+++ src/include/thirdparty/pcireg.h
@@ -4,17 +4,6 @@
 #ifndef _DEV_PCI_PCIREG_H_
 #define	_DEV_PCI_PCIREG_H_
 
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
 /*
  * Copyright (c) 1995, 1996, 1999, 2000
  *     Christopher G. Demetriou.  All rights reserved.
