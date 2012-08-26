$NetBSD: patch-libfdcore_fdcore-internal.h,v 1.1 2012/08/26 07:14:28 dholland Exp $

Avoid build failure if AI_ADDRCONFIG isn't available.

--- libfdcore/fdcore-internal.h~	2012-02-21 17:46:14.000000000 +0000
+++ libfdcore/fdcore-internal.h
@@ -41,6 +41,10 @@
 #include <freeDiameter/freeDiameter-host.h>
 #include <freeDiameter/libfdcore.h>
 
+#ifndef AI_ADDRCONFIG
+#define AI_ADDRCONFIG 0
+#endif
+
 #ifdef DISABLE_SCTP
 #undef IPPROTO_SCTP
 #define IPPROTO_SCTP	(2 = 4) /* some compilation error to spot the references */
