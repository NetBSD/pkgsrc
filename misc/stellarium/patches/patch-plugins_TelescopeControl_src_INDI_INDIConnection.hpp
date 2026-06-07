$NetBSD: patch-plugins_TelescopeControl_src_INDI_INDIConnection.hpp,v 1.5 2026/06/07 15:03:24 wiz Exp $

Compatibility with indi 2.2.2.
https://github.com/Stellarium/stellarium/issues/4959

--- plugins/TelescopeControl/src/INDI/INDIConnection.hpp.orig	2026-06-07 14:59:32.327629735 +0000
+++ plugins/TelescopeControl/src/INDI/INDIConnection.hpp
@@ -23,6 +23,10 @@
 #include <libindi/baseclient.h>
 #include <libindi/basedevice.h>
 
+#ifdef J2000
+#undef J2000
+#endif
+
 #include <mutex>
 #include <QStringList>
 
