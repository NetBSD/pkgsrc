$NetBSD: patch-src_config_afs__sysnames.h,v 1.7 2026/09/12 15:45:26 jakllsch Exp $

- Add SYS_NAME_IDs for NetBSD 8 to 9 on arm/i386/amd64

--- src/config/afs_sysnames.h.orig	2026-06-25 20:03:19.000000000 +0000
+++ src/config/afs_sysnames.h
@@ -311,6 +311,33 @@
 #define SYS_NAME_ID_i386_nbsd60         2543
 #define SYS_NAME_ID_amd64_nbsd70        2544
 #define SYS_NAME_ID_i386_nbsd70         2545
+#define SYS_NAME_ID_amd64_nbsd80        2546
+#define SYS_NAME_ID_arm32_nbsd80        2547
+#define SYS_NAME_ID_i386_nbsd80         2548
+#define SYS_NAME_ID_amd64_nbsd90        2549
+#define SYS_NAME_ID_i386_nbsd90         2550
+#define SYS_NAME_ID_macppc_nbsd100      2551
+#define SYS_NAME_ID_i386_nbsd100        SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_alpha_nbsd100       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_sparc_nbsd100       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_sparc64_nbsd100     SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_ppc_nbsd100         SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_amd64_nbsd100       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_arm32_nbsd100       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_i386_nbsd110        SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_alpha_nbsd110       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_sparc_nbsd110       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_sparc64_nbsd110     SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_ppc_nbsd110         SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_amd64_nbsd110       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_arm32_nbsd110       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_i386_nbsd120        SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_alpha_nbsd120       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_sparc_nbsd120       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_sparc64_nbsd120     SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_ppc_nbsd120         SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_amd64_nbsd120       SYS_NAME_ID_UNDEFINED
+#define SYS_NAME_ID_arm32_nbsd120       SYS_NAME_ID_UNDEFINED
 
 #define SYS_NAME_ID_i386_obsd31		2600
 #define SYS_NAME_ID_i386_obsd32		2601
