$NetBSD: patch-Source_cmMachO.h,v 1.1 2022/01/28 21:56:21 schmonz Exp $

Add missing include.

--- Source/cmMachO.h.orig	2022-01-25 13:45:06.000000000 +0000
+++ Source/cmMachO.h
@@ -6,6 +6,7 @@
 
 #include <iosfwd>
 #include <string>
+#include <memory>
 
 #if !defined(CMake_USE_MACH_PARSER)
 #  error "This file may be included only if CMake_USE_MACH_PARSER is enabled."
