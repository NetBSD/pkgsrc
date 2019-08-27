$NetBSD: patch-src_ConfigureChecks.cmake,v 1.2 2019/08/27 20:11:28 markd Exp $

Install in example dir

--- src/ConfigureChecks.cmake.orig	2019-08-03 19:51:11.000000000 +0000
+++ src/ConfigureChecks.cmake
@@ -224,7 +224,7 @@ if(KAUTH_HELPER_BACKEND_NAME STREQUAL "D
 
     # Install some files as well
     install( FILES backends/dbus/org.kde.kf5auth.conf
-             DESTINATION ${KDE_INSTALL_DBUSDIR}/system.d )
+             DESTINATION ${KDE_INSTALL_DATAROOTDIR}/examples/kauth )
 
     install( FILES backends/dbus/dbus_policy.stub
                    backends/dbus/dbus_service.stub
