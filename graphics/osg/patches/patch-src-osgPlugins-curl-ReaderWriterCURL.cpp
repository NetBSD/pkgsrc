$NetBSD: patch-src-osgPlugins-curl-ReaderWriterCURL.cpp,v 1.1 2011/09/24 12:58:11 joerg Exp $

--- src/osgPlugins/curl/ReaderWriterCURL.cpp.orig	2011-09-22 15:21:48.000000000 +0000
+++ src/osgPlugins/curl/ReaderWriterCURL.cpp
@@ -21,7 +21,6 @@
 #include <fstream>
 
 #include <curl/curl.h>
-#include <curl/types.h>
 
 #include "ReaderWriterCURL.h"
 
