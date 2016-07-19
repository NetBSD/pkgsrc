$NetBSD: patch-src--vp8--util--vpx_config.hh,v 1.1 2016/07/19 02:11:51 agc Exp $

Make this work on BSD_derived systems

--- src/vp8/util/vpx_config.hh	2016/07/17 17:50:27	1.1
+++ src/vp8/util/vpx_config.hh	2016/07/17 17:52:16
@@ -44,10 +44,11 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE       /* See feature_test_macros(7) */
 #endif
-#ifdef BSD
+#include <sys/param.h>
+#  if (defined(BSD) && BSD >= 199506)
 #include <sys/endian.h>
-#else
+#  else
 #include <endian.h>
-#endif
+#  endif
 #endif
 #endif
