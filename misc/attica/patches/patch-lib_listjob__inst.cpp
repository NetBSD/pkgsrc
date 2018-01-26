$NetBSD: patch-lib_listjob__inst.cpp,v 1.1 2018/01/26 15:16:29 jperkin Exp $

Fix namespace issue for clang.

--- lib/listjob_inst.cpp.orig	2013-04-30 22:45:43.000000000 +0000
+++ lib/listjob_inst.cpp
@@ -77,7 +77,7 @@
 #include "topicparser.h"
 
 
-using namespace Attica;
+namespace Attica {
 
 template class ListJob<Achievement>;
 template class ListJob<Activity>;
@@ -160,3 +160,4 @@ template class Parser<PublisherField>;
 template class Parser<RemoteAccount>;
 template class Parser<Topic>;
 
+};
