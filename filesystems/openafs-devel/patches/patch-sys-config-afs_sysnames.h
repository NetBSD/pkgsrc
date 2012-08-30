$NetBSD: patch-sys-config-afs_sysnames.h,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/config/afs_sysnames.h.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/config/afs_sysnames.h	2012-04-28 19:03:43.000000000 -0400
@@ -250,6 +250,8 @@
 #define SYS_NAME_ID_macppc_nbsd50       2541
 #define SYS_NAME_ID_amd64_nbsd60        2542
 #define SYS_NAME_ID_i386_nbsd60         2543
+#define SYS_NAME_ID_amd64_nbsd70        2544
+#define SYS_NAME_ID_i386_nbsd70         2545
 
 #define SYS_NAME_ID_i386_obsd31		2600
 #define SYS_NAME_ID_i386_obsd32		2601
