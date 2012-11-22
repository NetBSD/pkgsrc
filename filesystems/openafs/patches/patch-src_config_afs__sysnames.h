$NetBSD: patch-src_config_afs__sysnames.h,v 1.1 2012/11/22 22:22:45 jakllsch Exp $

--- src/config/afs_sysnames.h.orig	2010-12-17 15:58:42.000000000 +0000
+++ src/config/afs_sysnames.h
@@ -238,6 +238,8 @@
 #define SYS_NAME_ID_macppc_nbsd30 2539
 #define SYS_NAME_ID_macppc_nbsd40 2540
 #define SYS_NAME_ID_macppc_nbsd50 2541
+#define SYS_NAME_ID_amd64_nbsd60        2542
+#define SYS_NAME_ID_i386_nbsd60         2543
 
 #define SYS_NAME_ID_i386_obsd31		2600
 #define SYS_NAME_ID_i386_obsd32		2601
