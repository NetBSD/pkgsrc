$NetBSD: patch-src_downloader.cpp,v 1.1 2014/04/19 08:19:31 wiz Exp $

Fix path to jsoncpp headers.

--- src/downloader.cpp.orig	2014-03-09 21:06:14.000000000 +0000
+++ src/downloader.cpp
@@ -20,7 +20,7 @@
 #include <boost/regex.hpp>
 #include <boost/date_time/posix_time/posix_time_types.hpp>
 #include <tinyxml.h>
-#include <jsoncpp/json/json.h>
+#include <json/json.h>
 #include <htmlcxx/html/ParserDom.h>
 
 namespace bptime = boost::posix_time;
