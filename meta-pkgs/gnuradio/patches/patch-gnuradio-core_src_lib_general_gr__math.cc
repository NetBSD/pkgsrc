$NetBSD: patch-gnuradio-core_src_lib_general_gr__math.cc,v 1.1 2012/01/12 15:47:45 hans Exp $

--- gnuradio-core/src/lib/general/gr_math.cc.orig	2010-06-03 08:45:00.000000000 +0200
+++ gnuradio-core/src/lib/general/gr_math.cc	2011-10-12 17:08:22.292617060 +0200
@@ -82,6 +82,16 @@ gr_isnan (double value)
 // allows zero to be signed.  The comparison `-0.0 < 0.0'  is  false,  but
 // `gr_signbit (-0.0)' will return a nonzero value.
 
+#ifdef __sun
+#define signbit	sun_signbit
+int sun_signbit (double x)
+{
+  if (x < 0.0)
+    return 1;
+  return 0;
+}
+#endif
+
 #ifdef signbit
 
 int 
