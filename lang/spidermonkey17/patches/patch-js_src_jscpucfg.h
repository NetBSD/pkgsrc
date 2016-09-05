$NetBSD: patch-js_src_jscpucfg.h,v 1.2 2016/09/05 11:43:23 jperkin Exp $

Support alternate endian definitions.

--- js/src/jscpucfg.h.orig	2013-02-11 22:33:22.000000000 +0000
+++ js/src/jscpucfg.h
@@ -44,6 +44,21 @@
 #  define IS_BIG_ENDIAN 1
 # endif
 
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__MirBSD__) || defined(__DragonFly__)
+#include <sys/endian.h>
+
+#if defined(_BYTE_ORDER)
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#define IS_LITTLE_ENDIAN 1
+#undef  IS_BIG_ENDIAN
+#elif _BYTE_ORDER == _BIG_ENDIAN
+#undef  IS_LITTLE_ENDIAN
+#define IS_BIG_ENDIAN 1
+#endif
+#else /* !defined(_BYTE_ORDER) */
+#error "sys/endian.h does not define _BYTE_ORDER. Cannot determine endianness."
+#endif
+
 #elif defined(JS_HAVE_ENDIAN_H)
 # include <endian.h>
 
@@ -55,6 +70,14 @@
 #   undef  IS_LITTLE_ENDIAN
 #   define IS_BIG_ENDIAN 1
 #  endif
+# elif defined(BYTE_ORDER)
+#  if BYTE_ORDER == LITTLE_ENDIAN
+#   define IS_LITTLE_ENDIAN 1
+#   undef  IS_BIG_ENDIAN
+#  elif BYTE_ORDER == BIG_ENDIAN
+#   undef  IS_LITTLE_ENDIAN
+#   define IS_BIG_ENDIAN 1
+#  endif
 # else /* !defined(__BYTE_ORDER) */
 #  error "endian.h does not define __BYTE_ORDER. Cannot determine endianness."
 # endif
