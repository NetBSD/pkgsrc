$NetBSD: patch-src_t__prepro.h,v 1.1 2020/06/10 15:35:02 micha Exp $

The type label_t is not available on all OS, e.g. on SmartOS.
labelforname() is an unused function and the only place where label_t is used.

--- src/t_prepro.h.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/t_prepro.h
@@ -97,6 +97,8 @@ typedef enum    // section types
 
 /****** goto labels ***********/
 
+#if 0
 label_t * labelforname(char *labelname);
+#endif
 
 #endif
