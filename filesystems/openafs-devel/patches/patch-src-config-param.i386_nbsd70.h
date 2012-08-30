$NetBSD: patch-src-config-param.i386_nbsd70.h,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/config/param.i386_nbsd70.h.orig	2012-04-28 19:05:37.000000000 -0400
+++ src/config/param.i386_nbsd70.h	2012-04-28 19:05:59.000000000 -0400
@@ -0,0 +1,20 @@
+#ifndef        AFS_I386_PARAM_H
+#define        AFS_I386_PARAM_H
+
+#define AFS_X86_XBSD_ENV 1
+#define AFS_X86_ENV 1
+#define AFSLITTLE_ENDIAN 1
+
+#define SYS_NAME       "i386_nbsd70"
+#define SYS_NAME_ID    SYS_NAME_ID_i386_nbsd70
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
