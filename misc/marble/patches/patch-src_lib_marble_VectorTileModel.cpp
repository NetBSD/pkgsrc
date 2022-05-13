$NetBSD: patch-src_lib_marble_VectorTileModel.cpp,v 1.1 2022/05/13 17:06:01 jperkin Exp $

Avoid ambiguous function call.

--- src/lib/marble/VectorTileModel.cpp.orig	2021-02-27 00:23:23.000000000 +0000
+++ src/lib/marble/VectorTileModel.cpp
@@ -22,6 +22,8 @@
 #include <qmath.h>
 #include <QThreadPool>
 
+using std::log;
+
 namespace Marble
 {
 
