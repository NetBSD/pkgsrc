$NetBSD: patch-Source_Modules_FindLibUV.cmake,v 1.1 2018/06/24 09:13:22 adam Exp $

Find libuv 1.21.0 and newer.

--- Source/Modules/FindLibUV.cmake.orig	2018-06-24 07:50:12.000000000 +0000
+++ Source/Modules/FindLibUV.cmake
@@ -63,6 +63,8 @@ mark_as_advanced(LibUV_INCLUDE_DIR)
 set(_LibUV_H_REGEX "#[ \t]*define[ \t]+UV_VERSION_(MAJOR|MINOR|PATCH)[ \t]+[0-9]+")
 if(LibUV_INCLUDE_DIR AND EXISTS "${LibUV_INCLUDE_DIR}/uv-version.h")
   file(STRINGS "${LibUV_INCLUDE_DIR}/uv-version.h" _LibUV_H REGEX "${_LibUV_H_REGEX}")
+elseif(LibUV_INCLUDE_DIR AND EXISTS "${LibUV_INCLUDE_DIR}/uv/version.h")
+  file(STRINGS "${LibUV_INCLUDE_DIR}/uv/version.h" _LibUV_H REGEX "${_LibUV_H_REGEX}")
 elseif(LibUV_INCLUDE_DIR AND EXISTS "${LibUV_INCLUDE_DIR}/uv.h")
   file(STRINGS "${LibUV_INCLUDE_DIR}/uv.h" _LibUV_H REGEX "${_LibUV_H_REGEX}")
 else()
