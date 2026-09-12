$NetBSD: patch-src_config_param.amd64__nbsd110.h,v 1.1 2026/09/12 15:45:26 jakllsch Exp $

--- src/config/param.amd64_nbsd110.h.orig	2026-09-11 22:20:20.612087687 +0000
+++ src/config/param.amd64_nbsd110.h
@@ -0,0 +1,22 @@
+#ifndef AFS_AMD64_PARAM_H
+#define AFS_AMD64_PARAM_H
+
+#define AFS_X86_XBSD_ENV 1
+#define AFS_X86_ENV 1
+#define AFSLITTLE_ENDIAN 1
+
+#define SYS_NAME       "amd64_nbsd110"
+#define SYS_NAME_ID    SYS_NAME_ID_amd64_nbsd110
+
+#define AFS_64BITPOINTER_ENV  1
+#define AFS_64BITUSERPOINTER_ENV	1
+#ifndef UKERNEL
+/* This section for kernel libafs compiles only */
+
+#else /* !defined(UKERNEL) */
+
+/* This section for user space compiles only */
+
+#endif /* !defined(UKERNEL) */
+
+#endif /* AFS_AMD64_PARAM_H */
