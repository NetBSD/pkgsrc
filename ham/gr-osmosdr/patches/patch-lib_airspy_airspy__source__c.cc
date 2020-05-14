$NetBSD: patch-lib_airspy_airspy__source__c.cc,v 1.1 2020/05/14 19:21:34 joerg Exp $

--- lib/airspy/airspy_source_c.cc.orig	2020-05-10 20:51:56.395303506 +0000
+++ lib/airspy/airspy_source_c.cc
@@ -32,7 +32,6 @@
 
 #include <boost/assign.hpp>
 #include <boost/format.hpp>
-#include <boost/detail/endian.hpp>
 #include <boost/algorithm/string.hpp>
 #include <boost/thread/thread.hpp>
 
