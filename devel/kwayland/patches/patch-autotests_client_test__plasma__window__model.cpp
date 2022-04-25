$NetBSD: patch-autotests_client_test__plasma__window__model.cpp,v 1.1 2022/04/25 05:26:49 markd Exp $

linux/input.h only for linux

--- autotests/client/test_plasma_window_model.cpp.orig	2022-04-02 10:04:14.000000000 +0000
+++ autotests/client/test_plasma_window_model.cpp
@@ -17,7 +17,9 @@
 #include "../../src/server/plasmavirtualdesktop_interface.h"
 #include "../../src/server/plasmawindowmanagement_interface.h"
 
+#ifdef Q_OS_LINUX
 #include <linux/input.h>
+#endif
 
 using namespace KWayland::Client;
 using namespace KWayland::Server;
