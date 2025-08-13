$NetBSD: patch-src_include_OpenImageIO_strutil.h,v 1.4 2025/08/13 06:51:22 wiz Exp $

* For va_list.
https://github.com/AcademySoftwareFoundation/OpenImageIO/pull/4857

--- src/include/OpenImageIO/strutil.h.orig	2023-06-01 17:26:37.000000000 +0000
+++ src/include/OpenImageIO/strutil.h
@@ -15,6 +15,7 @@
 #pragma once
 
 #include <cstdio>
+#include <cstdarg>
 #include <map>
 #include <sstream>
 #include <string>
