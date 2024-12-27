$NetBSD: patch-plugins_TelescopeControl_src_INDI_INDIConnection.hpp,v 1.3 2024/12/27 18:19:27 adam Exp $

Fix includes.

--- plugins/TelescopeControl/src/INDI/INDIConnection.hpp.orig	2024-12-18 11:01:07.000000000 +0000
+++ plugins/TelescopeControl/src/INDI/INDIConnection.hpp
@@ -20,8 +20,8 @@
 #define INDICONNECTION_HPP
 
 #include <QObject>
-#include <libs/indiclient/baseclient.h>
-#include <libs/indidevice/basedevice.h>
+#include <libindi/baseclient.h>
+#include <libindi/basedevice.h>
 
 #include <mutex>
 #include <QStringList>
