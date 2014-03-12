$NetBSD: patch-src_dcc_dcccommon.cpp,v 1.1 2014/03/12 19:49:03 wiedi Exp $

Needed for SIOCGIFADDR on SunOS
--- src/dcc/dcccommon.cpp.orig	2014-01-15 01:53:02.000000000 +0000
+++ src/dcc/dcccommon.cpp
@@ -27,6 +27,9 @@
 #       include <stropts.h>
 #   endif
 #endif
+#if defined(__sun)
+#include <sys/sockio.h> 
+#endif
 #include <arpa/inet.h>
 
 #include <QHostAddress>
