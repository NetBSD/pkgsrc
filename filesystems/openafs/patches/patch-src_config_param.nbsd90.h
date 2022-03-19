$NetBSD: patch-src_config_param.nbsd90.h,v 1.2 2022/03/19 16:19:02 jakllsch Exp $

- Add support for NetBSD 9

--- src/config/param.nbsd90.h.orig	2022-03-18 17:06:12.819973595 +0000
+++ src/config/param.nbsd90.h
@@ -26,6 +26,8 @@
 #define AFS_NBSD50_ENV 1
 #define AFS_NBSD60_ENV 1
 #define AFS_NBSD70_ENV 1
+#define AFS_NBSD80_ENV 1
+#define AFS_NBSD90_ENV 1
 #undef  AFS_NONFSTRANS
 #define AFS_NONFSTRANS 1
 
@@ -37,6 +39,8 @@
 #define AFS_HAVE_STATVFS    1	/* System supports statvfs */
 #endif
 
+#define ROOTINO UFS_ROOTINO
+
 #ifndef UKERNEL
 
 #if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__) && !defined(IGNORE_STDS_H)
