$NetBSD: patch-src_config_param.nbsd70.h,v 1.1 2016/04/04 12:48:29 jakllsch Exp $

--- src/config/param.nbsd70.h.orig	2016-04-03 18:39:15.000000000 +0000
+++ src/config/param.nbsd70.h
@@ -41,6 +41,8 @@
 #define AFS_NBSD30_ENV 1
 #define AFS_NBSD40_ENV 1
 #define AFS_NBSD50_ENV 1
+#define AFS_NBSD60_ENV 1
+#define AFS_NBSD70_ENV 1
 #undef  AFS_NONFSTRANS
 #define AFS_NONFSTRANS 1
 
@@ -52,6 +54,8 @@
 #define AFS_HAVE_STATVFS    1	/* System supports statvfs */
 #endif
 
+#define ROOTINO UFS_ROOTINO
+
 #ifndef UKERNEL
 
 #if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
