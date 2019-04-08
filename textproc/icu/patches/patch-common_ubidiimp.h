$NetBSD: patch-common_ubidiimp.h,v 1.1 2019/04/08 21:39:43 jperkin Exp $

Avoid sys/regset.h pollution on SunOS.

--- common/ubidiimp.h.orig	2019-03-27 18:47:14.000000000 +0000
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
 
 typedef uint8_t DirProp;
