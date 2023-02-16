$NetBSD: patch-src_config_param.ppc_nbsd100.h,v 1.1 2023/02/16 18:56:44 he Exp $

--- src/config/param.ppc_nbsd100.h.orig	2023-02-16 19:16:24.549771760 +0100
+++ src/config/param.ppc_nbsd100.h	2023-02-16 19:21:11.780631671 +0100
@@ -0,0 +1,10 @@
+#ifndef	AFS_PPC_PARAM_H
+#define	AFS_PPC_PARAM_H
+
+#define SYS_NAME       "macppc_nbsd100"
+#define SYS_NAME_ID    SYS_NAME_ID_macppc_nbsd100
+
+#define AFS_PPC_ENV 1
+#define AFSBIG_ENDIAN   1
+
+#endif /* AFS_PCC_PARAM_H */
