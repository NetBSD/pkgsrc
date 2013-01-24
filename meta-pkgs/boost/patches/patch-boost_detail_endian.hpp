$NetBSD: patch-boost_detail_endian.hpp,v 1.1 2013/01/24 22:54:49 riz Exp $

--- boost/detail/endian.hpp.orig	2011-03-29 14:58:48.000000000 -0700
+++ boost/detail/endian.hpp	2013-01-24 14:24:28.000000000 -0800
@@ -43,6 +43,23 @@
 #  error Unknown machine endianness detected.
 # endif
 # define BOOST_BYTE_ORDER __BYTE_ORDER
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || \
+    defined(__OpenBSD__) || (__DragonFly__)
+#  if defined(__OpenBSD__)
+#  include <machine/endian.h>
+#  else
+#  include <sys/endian.h>
+#  endif
+# if (_BYTE_ORDER == _LITTLE_ENDIAN)
+#  define BOOST_LITTLE_ENDIAN
+# elif (_BYTE_ORDER == _BIG_ENDIAN)
+#  define BOOST_BIG_ENDIAN
+# elif (_BYTE_ORDER == _PDP_ENDIAN)
+#  define BOOST_PDP_ENDIAN
+# else
+#  error Unknown machine endianness detected.
+# endif
+# define BOOST_BYTE_ORDER __BYTE_ORDER
 #elif defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN) || \
     defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__) || \
     defined(_STLP_BIG_ENDIAN) && !defined(_STLP_LITTLE_ENDIAN)
