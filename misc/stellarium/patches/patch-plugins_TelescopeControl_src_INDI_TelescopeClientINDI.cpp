$NetBSD: patch-plugins_TelescopeControl_src_INDI_TelescopeClientINDI.cpp,v 1.1 2024/12/27 18:19:27 adam Exp $

Fix includes.

--- plugins/TelescopeControl/src/INDI/TelescopeClientINDI.cpp.orig	2024-12-27 17:32:15.315769380 +0000
+++ plugins/TelescopeControl/src/INDI/TelescopeClientINDI.cpp
@@ -25,7 +25,7 @@
 
 #include "StelCore.hpp"
 #include "StelUtils.hpp"
-#include <libs/indibase/inditelescope.h>
+#include <libindi/inditelescope.h>
 #include "INDIControlWidget.hpp"
 
 TelescopeClientINDI::TelescopeClientINDI(const QString &name, const QString &params):
