$NetBSD: patch-include_common.h,v 1.1 2012/02/16 13:46:52 hans Exp $

--- include/common.h.orig	2008-02-11 03:58:08.000000000 +0100
+++ include/common.h	2012-01-20 00:50:51.945230165 +0100
@@ -111,6 +111,10 @@ enum faultcode_
 	fault_unimplemented	= 14
 };
 
+#ifdef __sun
+#undef faultcode_t
+#endif
+
 typedef enum faultcode_ faultcode_t;
 
 #if defined(__GNUC__) || defined(__INTEL_COMPILER)
