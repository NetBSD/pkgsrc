$NetBSD: patch-src_include_OpenImageIO_strutil.h,v 1.3 2023/10/15 19:52:09 ryoon Exp $

* For va_list.

--- src/include/OpenImageIO/strutil.h.orig	2023-06-01 17:26:37.000000000 +0000
+++ src/include/OpenImageIO/strutil.h
@@ -15,6 +15,7 @@
 #pragma once
 
 #include <cstdio>
+#include <cstdarg>
 #include <map>
 #include <sstream>
 #include <string>
