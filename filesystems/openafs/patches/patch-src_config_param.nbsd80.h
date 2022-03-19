$NetBSD: patch-src_config_param.nbsd80.h,v 1.2 2022/03/19 16:19:02 jakllsch Exp $

- Add support for NetBSD 8

--- src/config/param.nbsd80.h.orig	2022-03-18 17:06:12.813417775 +0000
+++ src/config/param.nbsd80.h
@@ -26,6 +26,7 @@
 #define AFS_NBSD50_ENV 1
 #define AFS_NBSD60_ENV 1
 #define AFS_NBSD70_ENV 1
+#define AFS_NBSD80_ENV 1
 #undef  AFS_NONFSTRANS
 #define AFS_NONFSTRANS 1
 
@@ -37,6 +38,8 @@
 #define AFS_HAVE_STATVFS    1	/* System supports statvfs */
 #endif
 
+#define ROOTINO UFS_ROOTINO
+
 #ifndef UKERNEL
 
 #if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
