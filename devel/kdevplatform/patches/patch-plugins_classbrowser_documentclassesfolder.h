$NetBSD: patch-plugins_classbrowser_documentclassesfolder.h,v 1.1 2014/11/14 22:43:59 markd Exp $

Work around: Parse error at "BOOST_JOIN"

--- plugins/classbrowser/documentclassesfolder.h.orig	2014-08-26 19:49:48.000000000 +0000
+++ plugins/classbrowser/documentclassesfolder.h
@@ -23,9 +23,11 @@
 #define KDEVPLATFORM_PLUGIN_DOCUMENTCLASSESFOLDER_H
 
 #include "classmodelnode.h"
+#ifndef Q_MOC_RUN
 #include <boost/multi_index_container.hpp>
 #include <boost/multi_index/member.hpp>
 #include <boost/multi_index/ordered_index.hpp>
+#endif
 
 namespace ClassModelNodes
 {
