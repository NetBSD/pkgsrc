$NetBSD: patch-par2cmdline.h,v 1.1 2016/09/16 17:31:54 jperkin Exp $

Use GCC macros on SunOS, _LITTLE_ENDIAN is defined but not set.

--- par2cmdline.h.orig	2015-08-02 16:09:46.000000000 +0000
+++ par2cmdline.h
@@ -154,11 +154,14 @@ typedef unsigned long long u64;
 #if HAVE_ENDIAN_H
 #  include <endian.h>
 #  ifndef __LITTLE_ENDIAN
-#    ifdef _LITTLE_ENDIAN
-#      define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#    if defined(_LITTLE_ENDIAN) && !defined(__sun)
 #      define __LITTLE_ENDIAN _LITTLE_ENDIAN
 #      define __BIG_ENDIAN _BIG_ENDIAN
 #      define __PDP_ENDIAN _PDP_ENDIAN
+#    elif defined(__ORDER_LITTLE_ENDIAN__)
+#      define __LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
+#      define __BIG_ENDIAN __ORDER_BIG_ENDIAN__
+#      define __PDP_ENDIAN __ORDER_PDP_ENDIAN__
 #    else
 #      error <endian.h> does not define __LITTLE_ENDIAN etc.
 #    endif
