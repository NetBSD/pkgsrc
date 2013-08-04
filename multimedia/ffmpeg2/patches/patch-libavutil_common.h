$NetBSD: patch-libavutil_common.h,v 1.1 2013/08/04 10:29:02 adam Exp $

--- libavutil/common.h.orig	2013-01-06 21:53:29.000000000 +0000
+++ libavutil/common.h
@@ -39,6 +39,22 @@
 #include "version.h"
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
