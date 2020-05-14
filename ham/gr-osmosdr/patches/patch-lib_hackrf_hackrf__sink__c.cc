$NetBSD: patch-lib_hackrf_hackrf__sink__c.cc,v 1.1 2020/05/14 19:21:34 joerg Exp $

--- lib/hackrf/hackrf_sink_c.cc.orig	2020-05-10 20:51:58.688391524 +0000
+++ lib/hackrf/hackrf_sink_c.cc
@@ -39,7 +39,6 @@
 
 #include <boost/assign.hpp>
 #include <boost/format.hpp>
-#include <boost/detail/endian.hpp>
 #include <boost/algorithm/string.hpp>
 #include <boost/thread/thread.hpp>
 
