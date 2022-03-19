$NetBSD: patch-src_config_afs__sysnames.h,v 1.5 2022/03/19 16:19:02 jakllsch Exp $

- Add SYS_NAME_IDs for NetBSD 8 to 9 on arm/i386/amd64

--- src/config/afs_sysnames.h.orig	2021-12-09 17:07:41.000000000 +0000
+++ src/config/afs_sysnames.h
@@ -297,6 +297,11 @@
 #define SYS_NAME_ID_i386_nbsd60         2543
 #define SYS_NAME_ID_amd64_nbsd70        2544
 #define SYS_NAME_ID_i386_nbsd70         2545
+#define SYS_NAME_ID_amd64_nbsd80        2546
+#define SYS_NAME_ID_arm32_nbsd80        2547
+#define SYS_NAME_ID_i386_nbsd80         2548
+#define SYS_NAME_ID_amd64_nbsd90        2549
+#define SYS_NAME_ID_i386_nbsd90         2550
 
 #define SYS_NAME_ID_i386_obsd31		2600
 #define SYS_NAME_ID_i386_obsd32		2601
