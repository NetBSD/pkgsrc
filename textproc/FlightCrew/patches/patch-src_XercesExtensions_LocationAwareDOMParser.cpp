$NetBSD: patch-src_XercesExtensions_LocationAwareDOMParser.cpp,v 1.1 2012/11/16 20:08:25 joerg Exp $

--- src/XercesExtensions/LocationAwareDOMParser.cpp.orig	2012-11-16 11:24:04.000000000 +0000
+++ src/XercesExtensions/LocationAwareDOMParser.cpp
@@ -29,7 +29,7 @@
 // super class call the handle() method of the handler.
 // We only ever need a single handler and a const one at that... this could
 // also easily go into a singleton, but this approach is simpler.
-static const XercesExt::LocationInfoDataHandler LOCATION_DATA_HANDLER;
+static XercesExt::LocationInfoDataHandler LOCATION_DATA_HANDLER;
 const char *LOCATION_INFO_KEY = "LocationInfoKey";
 typedef unsigned int uint; 
 
