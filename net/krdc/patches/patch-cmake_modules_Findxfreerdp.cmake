$NetBSD: patch-cmake_modules_Findxfreerdp.cmake,v 1.1 2022/09/29 01:09:36 markd Exp $

pkgsrc renames it xfreerdp2

--- cmake/modules/Findxfreerdp.cmake.orig	2022-08-10 22:13:22.000000000 +0000
+++ cmake/modules/Findxfreerdp.cmake
@@ -1,7 +1,7 @@
 # SPDX-License-Identifier: BSD-3-Clause
 # SPDX-FileCopyrightText: 2021 Harald Sitter <sitter@kde.org>
 
-find_program(${CMAKE_FIND_PACKAGE_NAME}_PATH xfreerdp)
+find_program(${CMAKE_FIND_PACKAGE_NAME}_PATH xfreerdp2)
 
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(${CMAKE_FIND_PACKAGE_NAME}
