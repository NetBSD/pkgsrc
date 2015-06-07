$NetBSD: patch-ext_common_conv.h,v 1.1 2015/06/07 10:50:27 taca Exp $

* Use more portable macro.

--- ext/common/conv.h.orig	2015-05-30 13:44:54.000000000 +0000
+++ ext/common/conv.h
@@ -30,7 +30,7 @@
 #if RUBY_VERSION <190
 #define	FLOAT_VAL_ACCESS(val) RFLOAT(val)->value
 #else
-#define	FLOAT_VAL_ACCESS(val) RFLOAT(val)->float_value
+#define	FLOAT_VAL_ACCESS(val) RFLOAT_VALUE((val))
 #endif
 
 #define FASTCONV(_name_,_type_,_convfix_,_convfallback_) \
