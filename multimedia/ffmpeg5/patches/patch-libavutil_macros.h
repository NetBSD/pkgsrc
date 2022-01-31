$NetBSD: patch-libavutil_macros.h,v 1.1 2022/01/31 23:16:41 ryoon Exp $

Add required int includes on various opensource platforms.

--- libavutil/macros.h.orig	2022-01-14 18:45:40.000000000 +0000
+++ libavutil/macros.h
@@ -27,6 +27,22 @@
 
 #include "libavutil/avconfig.h"
 
+#if defined(__cplusplus)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__linux__)
+#undef _STDINT_H_
+#undef _SYS_STDINT_H_
+#undef _STDINT_H
+#undef _GCC_WRAP_STDINT_H
+#ifndef __STDC_CONSTANT_MACROS
+#define __STDC_CONSTANT_MACROS
+#endif
+#include <stdint.h>
+#endif /* FreeBSD | OpenBSD | linux */
+#if defined(__DragonFly__) || defined(__NetBSD__)
+#include <machine/int_const.h>
+#endif /* DragonFly | NetBSD */
+#endif /* __cplusplus */
+
 #if AV_HAVE_BIGENDIAN
 #   define AV_NE(be, le) (be)
 #else
