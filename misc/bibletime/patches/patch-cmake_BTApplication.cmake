$NetBSD: patch-cmake_BTApplication.cmake,v 1.1 2020/12/04 12:17:58 nros Exp $

* don't install DisplayView.qml in bin
 taken from upstream https://github.com/bibletime/bibletime/commit/7700e93a345c202cd45cd4e72b77feb64fe33b80

--- cmake/BTApplication.cmake.orig	2020-08-02 18:32:25.000000000 +0000
+++ cmake/BTApplication.cmake
@@ -178,10 +178,10 @@ INSTALL(FILES "docs/license.html"
 # See QTBUG-55259, Affects windeployqt and macdeployqt
 IF(APPLE)
     INSTALL(FILES "src/frontend/display/modelview/DisplayView.qml"
-        DESTINATION "${BT_BINDIR}/BibleTime.app/Contents/MacOS")
+        DESTINATION "${BT_BINDIR}/BibleTime.app/share/bibletime/qml")
 ELSE()
     INSTALL(FILES "src/frontend/display/modelview/DisplayView.qml"
-        DESTINATION "${BT_BINDIR}/")
+        DESTINATION "${BT_DATAROOTDIR}/bibletime/qml")
 ENDIF()
 
 FILE(GLOB INSTALL_TMPL_LIST
