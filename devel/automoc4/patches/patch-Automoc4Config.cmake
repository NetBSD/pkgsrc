$NetBSD: patch-Automoc4Config.cmake,v 1.1 2025/08/20 11:19:09 wiz Exp $

From: Stephen Kelly <steveire@gmail.com>
Date: Sun, 19 Jul 2015 19:24:51 +0000
Subject: Don't attempt to add dependencies which do not exist.
X-Git-Url: http://quickgit.kde.org/?p=automoc.git&a=commitdiff&h=48f6e64d98e4aaa47f2a49faa5f3e821bc21fd6e
---
Don't attempt to add dependencies which do not exist.
---

--- Automoc4Config.cmake.orig	2025-08-20 11:15:50.540346321 +0000
+++ Automoc4Config.cmake
@@ -114,7 +114,6 @@ macro(AUTOMOC4 _target_NAME _SRCS)
    if(_moc_files)
       set(_automoc_source "${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}_automoc.cpp")
       get_directory_property(_moc_incs INCLUDE_DIRECTORIES)
-      get_directory_property(_moc_defs DEFINITIONS)
       get_directory_property(_moc_cdefs COMPILE_DEFINITIONS)
 
       # configure_file replaces _moc_files, _moc_incs, _moc_cdefs and _moc_defs
@@ -176,7 +175,6 @@ macro(_ADD_AUTOMOC4_TARGET _target_NAME 
       set(_automoc_source "${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}.cpp")
       set(_automoc_dotFiles "${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}.cpp.files")
       get_directory_property(_moc_incs INCLUDE_DIRECTORIES)
-      get_directory_property(_moc_defs DEFINITIONS)
       get_directory_property(_moc_cdefs COMPILE_DEFINITIONS)
 
       # configure_file replaces _moc_files, _moc_incs, _moc_cdefs and _moc_defs
@@ -245,5 +243,7 @@ endmacro(_AUTOMOC4_KDE4_PRE_TARGET_HANDL
 
 
 macro(_AUTOMOC4_KDE4_POST_TARGET_HANDLING _target)
-   add_dependencies(${_target} "${_target}_automoc")
+  if (TARGET "${_target}_automoc")
+    add_dependencies(${_target} "${_target}_automoc")
+  endif()
 endmacro(_AUTOMOC4_KDE4_POST_TARGET_HANDLING)
