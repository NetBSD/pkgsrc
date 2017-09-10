$NetBSD: patch-tagging.h,v 1.1 2017/09/10 01:44:32 dholland Exp $

Work around namespace conflict from libevent.

--- tagging.h~	2006-08-19 07:10:41.000000000 +0000
+++ tagging.h
@@ -33,6 +33,9 @@
 #ifndef _TAGGING_
 #define _TAGGING_
 
+/* work around namespace conflict from libevent */
+#undef encode_int
+
 void tagging_init(void);
 
 #define SHINGLE_MIN	32
