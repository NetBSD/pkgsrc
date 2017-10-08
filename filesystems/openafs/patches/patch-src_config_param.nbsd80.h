$NetBSD: patch-src_config_param.nbsd80.h,v 1.1 2017/10/08 02:41:39 sevan Exp $

- Add support for NetBSD 8

--- src/config/param.nbsd80.h.orig	2017-07-15 22:37:07.451884000 +0000
+++ src/config/param.nbsd80.h
@@ -41,6 +41,9 @@
 #define AFS_NBSD30_ENV 1
 #define AFS_NBSD40_ENV 1
 #define AFS_NBSD50_ENV 1
+#define AFS_NBSD60_ENV 1
+#define AFS_NBSD70_ENV 1
+#define AFS_NBSD80_ENV 1
 #undef  AFS_NONFSTRANS
 #define AFS_NONFSTRANS 1
 
@@ -52,6 +55,8 @@
 #define AFS_HAVE_STATVFS    1	/* System supports statvfs */
 #endif
 
+#define ROOTINO UFS_ROOTINO
+
 #ifndef UKERNEL
 
 #if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
