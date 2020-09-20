$NetBSD: patch-src_config_param.nbsd90.h,v 1.1 2020/09/20 22:15:00 jakllsch Exp $

- Add support for NetBSD 9

--- src/config/param.nbsd90.h.orig	2020-09-20 22:11:06.272187304 +0000
+++ src/config/param.nbsd90.h
@@ -41,6 +41,10 @@
 #define AFS_NBSD30_ENV 1
 #define AFS_NBSD40_ENV 1
 #define AFS_NBSD50_ENV 1
+#define AFS_NBSD60_ENV 1
+#define AFS_NBSD70_ENV 1
+#define AFS_NBSD80_ENV 1
+#define AFS_NBSD90_ENV 1
 #undef  AFS_NONFSTRANS
 #define AFS_NONFSTRANS 1
 
@@ -52,6 +56,8 @@
 #define AFS_HAVE_STATVFS    1	/* System supports statvfs */
 #endif
 
+#define ROOTINO UFS_ROOTINO
+
 #ifndef UKERNEL
 
 #if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
