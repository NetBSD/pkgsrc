$NetBSD: patch-src_mumble_UserInformation.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/UserInformation.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/UserInformation.cpp
@@ -34,11 +34,13 @@
 
 #include "Audio.h"
 #include "CELTCodec.h"
-#include "Global.h"
 #include "Net.h"
 #include "ServerHandler.h"
 #include "ViewCert.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 static QString decode_utf8_qssl_string(const QString &input) {
 	QString i = input;
 	return QUrl::fromPercentEncoding(i.replace(QLatin1String("\\x"), QLatin1String("%")).toLatin1());
