$NetBSD: patch-src_core_RMetaTypes.h,v 1.1.2.2 2016/10/15 18:02:14 bsiegert Exp $

Fix 32-bit build, where some of the integer types overlap. PR 51509.

--- src/core/RMetaTypes.h~	2016-08-29 06:49:22.000000000 +0000
+++ src/core/RMetaTypes.h
@@ -140,7 +140,9 @@
 #include "RSingleApplication.h"
 
 Q_DECLARE_METATYPE(int*)
+#ifdef _LP64
 Q_DECLARE_METATYPE(unsigned int*)
+#endif
 Q_DECLARE_METATYPE(qint64*)
 
 #if !defined Q_OS_WIN && !defined Q_OS_LINUX && !defined Q_OS_FREEBSD
