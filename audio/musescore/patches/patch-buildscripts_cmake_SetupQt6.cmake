$NetBSD: patch-buildscripts_cmake_SetupQt6.cmake,v 1.1 2025/11/23 03:20:56 gutteridge Exp $

Fix building with Qt 6.10.

--- buildscripts/cmake/SetupQt6.cmake.orig	2025-10-21 08:21:23.000000000 +0000
+++ buildscripts/cmake/SetupQt6.cmake
@@ -25,6 +25,7 @@ endif()
 set(qt_components
     Core
     Gui
+    GuiPrivate
     Widgets
     Network
     Qml
