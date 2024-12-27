$NetBSD: patch-plugins_TelescopeControl_src_INDI_INDIConnection.cpp,v 1.2 2024/12/27 18:19:27 adam Exp $

Fix includes.

--- plugins/TelescopeControl/src/INDI/INDIConnection.cpp.orig	2024-12-18 11:01:07.000000000 +0000
+++ plugins/TelescopeControl/src/INDI/INDIConnection.cpp
@@ -25,9 +25,9 @@
 #include <limits>
 #include <cmath>
 
-#include <libs/indiclient/baseclient.h>
-#include <libs/indidevice/basedevice.h>
-#include <libs/indibase/inditelescope.h>
+#include <libindi/baseclient.h>
+#include <libindi/basedevice.h>
+#include <libindi/inditelescope.h>
 
 const int INDIConnection::SLEW_STOP = INDI::Telescope::SLEW_GUIDE - 1;
 
