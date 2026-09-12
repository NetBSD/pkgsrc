$NetBSD: patch-src_config_param.i386__nbsd110.h,v 1.1 2026/09/12 15:45:26 jakllsch Exp $

--- src/config/param.i386_nbsd110.h.orig	2026-09-11 22:20:20.610585327 +0000
+++ src/config/param.i386_nbsd110.h
@@ -0,0 +1,20 @@
+#ifndef        AFS_I386_PARAM_H
+#define        AFS_I386_PARAM_H
+
+#define AFS_X86_XBSD_ENV 1
+#define AFS_X86_ENV 1
+#define AFSLITTLE_ENDIAN 1
+
+#define SYS_NAME       "i386_nbsd110"
+#define SYS_NAME_ID    SYS_NAME_ID_i386_nbsd110
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
+#endif /* AFS_I386_PARAM_H */
