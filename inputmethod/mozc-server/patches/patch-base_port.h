$NetBSD: patch-base_port.h,v 1.1 2015/10/12 07:24:51 ryoon Exp $

--- base/port.h.orig	2015-09-05 17:32:12.000000000 +0000
+++ base/port.h
@@ -130,6 +130,10 @@ static const  int64 kint64max  = (( int6
 #define AS_STRING(x)   AS_STRING_INTERNAL(x)
 #define AS_STRING_INTERNAL(x)   #x
 
+// gcc>=46 has nullptr, otherwise use __null instead.
+#if defined(__GNUC__) && __GNUC__ * 1000 + __GNUC__MINOR__ < 4006
+#define nullptr __null
+#endif
 
 // TODO(yukawa): Simplify following includes
 #include "base/flags.h"
