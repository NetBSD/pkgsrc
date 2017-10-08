$NetBSD: patch-src_config_param.armv6_nbsd80.h,v 1.1 2017/10/08 02:41:39 sevan Exp $

- Add support for NetBSD 8 on armv6 based on filename but generic in content to be
  applicable to other generations of ARM

--- src/config/param.armv6_nbsd80.h.orig	2017-07-15 19:52:25.315668000 +0000
+++ src/config/param.armv6_nbsd80.h
@@ -0,0 +1,19 @@
+#ifndef        AFS_PARAM_H
+#define        AFS_PARAM_H
+
+#define AFS_ARM32_XBSD_ENV 1
+#define AFSLITTLE_ENDIAN 1
+
+#define SYS_NAME       "arm32_nbsd80"
+#define SYS_NAME_ID    SYS_NAME_ID_arm32_nbsd80
+
+#ifndef UKERNEL
+/* This section for kernel libafs compiles only */
+
+#else /* !defined(UKERNEL) */
+
+/* This section for user space compiles only */
+
+#endif /* !defined(UKERNEL) */
+
+#endif /* AFS_PARAM_H */
