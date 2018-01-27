$NetBSD: patch-cmake_KF5AuthMacros.cmake,v 1.1 2018/01/27 19:08:12 markd Exp $

Allow overriding the dbus-1/system.d install directory

--- cmake/KF5AuthMacros.cmake.orig	2017-12-02 20:02:04.000000000 +0000
+++ cmake/KF5AuthMacros.cmake
@@ -32,12 +32,15 @@
 # to a DBus policy to let the helper register on the system bus, and a service file for letting the helper
 # being automatically activated by the system bus.
 # *WARNING* You have to install the helper in ${KAUTH_HELPER_INSTALL_DIR} to make sure everything will work.
+
+set(KAUTH_DBUS_DIR  ${SYSCONF_INSTALL_DIR}/dbus-1/system.d/ CACHE PATH "DBus system directory")
+
 function(KAUTH_INSTALL_HELPER_FILES HELPER_TARGET HELPER_ID HELPER_USER)
     if(KAUTH_HELPER_BACKEND_NAME STREQUAL "DBUS")
         configure_file(${KAUTH_STUB_FILES_DIR}/dbus_policy.stub
                         ${CMAKE_CURRENT_BINARY_DIR}/${HELPER_ID}.conf)
         install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${HELPER_ID}.conf
-                DESTINATION ${SYSCONF_INSTALL_DIR}/dbus-1/system.d/)
+                DESTINATION ${KAUTH_DBUS_DIR})
 
         configure_file(${KAUTH_STUB_FILES_DIR}/dbus_service.stub
                         ${CMAKE_CURRENT_BINARY_DIR}/${HELPER_ID}.service)
