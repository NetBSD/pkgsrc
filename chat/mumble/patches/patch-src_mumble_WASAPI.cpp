$NetBSD: patch-src_mumble_WASAPI.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/WASAPI.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/WASAPI.cpp
@@ -32,10 +32,11 @@
 
 #include "WASAPI.h"
 #include "WASAPINotificationClient.h"
-#include "Global.h"
 #include "Timer.h"
 #include "User.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
 
 // Now that Win7 is published, which includes public versions of these
 // interfaces, we simply inherit from those but use the "old" IIDs.
