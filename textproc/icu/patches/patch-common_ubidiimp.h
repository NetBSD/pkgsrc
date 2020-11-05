$NetBSD: patch-common_ubidiimp.h,v 1.2 2020/11/05 08:58:41 ryoon Exp $

Avoid sys/regset.h pollution on SunOS.

--- common/ubidiimp.h.orig	2020-10-28 21:21:12.000000000 +0000
+++ common/ubidiimp.h
@@ -24,6 +24,11 @@
 #include "unicode/uchar.h"
 #include "ubidi_props.h"
 
+#ifdef __sun
+#undef CS
+#undef ES
+#endif
+
 /* miscellaneous definitions ---------------------------------------------- */
 
 // ICU-20853=ICU-20935 Solaris #defines CS and ES in sys/regset.h
