$NetBSD: patch-src_ConfigureChecks.cmake,v 1.1 2016/05/26 09:09:24 markd Exp $

Install in example dir

--- src/ConfigureChecks.cmake.orig	2016-02-06 13:36:29.000000000 +0000
+++ src/ConfigureChecks.cmake
@@ -222,7 +222,7 @@ if(KAUTH_HELPER_BACKEND_NAME STREQUAL "D
 
     # Install some files as well
     install( FILES backends/dbus/org.kde.kf5auth.conf
-             DESTINATION ${SYSCONF_INSTALL_DIR}/dbus-1/system.d )
+             DESTINATION ${KDE_INSTALL_DATAROOTDIR}/examples/kauth )
 
     install( FILES backends/dbus/dbus_policy.stub
                    backends/dbus/dbus_service.stub
