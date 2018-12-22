$NetBSD: patch-src_mumble_mumble__pch.hpp,v 1.1 2018/12/22 18:17:39 nia Exp $

https://github.com/mumble-voip/mumble/pull/3287

--- src/mumble/mumble_pch.hpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/mumble_pch.hpp
@@ -71,6 +71,8 @@
 #include <boost/typeof/typeof.hpp>
 #include <boost/weak_ptr.hpp>
 
+#include <cmath>
+
 #ifdef Q_OS_WIN
 #include <shellapi.h>
 #include <winsock2.h>
