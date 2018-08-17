$NetBSD: patch-src_libcmis_xml-utils.cxx,v 1.1 2018/08/17 17:21:24 wiz Exp $

Fix build with boost-1.68.0.
https://github.com/tdf/libcmis/issues/19

--- src/libcmis/xml-utils.cxx.orig	2016-03-01 16:14:26.000000000 +0000
+++ src/libcmis/xml-utils.cxx
@@ -31,7 +31,7 @@
 #include <sstream>
 #include <stdlib.h>
 
-#include <boost/uuid/sha1.hpp>
+#include <boost/uuid/detail/sha1.hpp>
 #include <curl/curl.h>
 
 #include "xml-utils.hxx"
