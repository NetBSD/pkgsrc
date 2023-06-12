$NetBSD: patch-dircompat.h,v 1.1 2023/06/12 21:41:59 schmonz Exp $

Extract compat definitions for easy inclusion elsewhere.

--- dircompat.h.orig	2023-06-12 21:24:40.055455063 +0000
+++ dircompat.h
@@ -0,0 +1,18 @@
+#ifndef DIRCOMPAT_H
+#define DIRCOMPAT_H
+
+#if defined(DT_UNKNOWN) && !defined(NO_D_TYPE_IN_DIRENT)
+#define DTYPE(de)	((de)->d_type)
+#else
+#undef DT_UNKNOWN
+#undef DT_DIR
+#undef DT_REG
+#undef DT_LNK
+#define DT_UNKNOWN	0
+#define DT_DIR		1
+#define DT_REG		2
+#define DT_LNK		3
+#define DTYPE(de)	DT_UNKNOWN
+#endif
+
+#endif
