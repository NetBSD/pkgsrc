$NetBSD: patch-src_tests_mult-s16-test.c,v 1.1 2014/06/09 13:08:19 ryoon Exp $

Define glibc-specific (?) __WORDSIZE.

--- src/tests/mult-s16-test.c.orig	2014-01-23 18:57:55.000000000 +0000
+++ src/tests/mult-s16-test.c
@@ -30,6 +30,14 @@
 #include <pulsecore/random.h>
 #include <pulsecore/macro.h>
 
+#if !defined __WORDSIZE
+# if defined __LP64__
+#  define __WORDSIZE     64
+# else
+#  define __WORDSIZE     32
+# endif
+#endif
+
 #include "runtime-test-util.h"
 
 static inline int32_t pa_mult_s16_volume_32(int16_t v, int32_t cv) {
