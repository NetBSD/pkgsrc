$NetBSD: patch-src_mumble_WASAPINotificationClient.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/WASAPINotificationClient.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/WASAPINotificationClient.cpp
@@ -29,13 +29,15 @@
 */
 
 #include <initguid.h>
-#include <Global.h>
 #include <QMutexLocker>
 #include "MainWindow.h"
 #include <boost/thread/once.hpp>
 
 #include "WASAPINotificationClient.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 HRESULT STDMETHODCALLTYPE WASAPINotificationClient::OnDefaultDeviceChanged(EDataFlow flow, ERole role, LPCWSTR pwstrDefaultDevice) {
 	const QString device = QString::fromWCharArray(pwstrDefaultDevice);
 
