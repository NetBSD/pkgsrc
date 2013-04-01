$NetBSD: patch-binfilter_inc_bf__xmloff_SchXMLExportHelper.hxx,v 1.1 2013/04/01 12:19:13 joerg Exp $

--- binfilter/inc/bf_xmloff/SchXMLExportHelper.hxx.orig	2013-03-30 17:32:58.000000000 +0000
+++ binfilter/inc/bf_xmloff/SchXMLExportHelper.hxx
@@ -40,6 +40,8 @@
 #include <com/sun/star/util/XStringMapping.hpp>
 #endif
 
+#include <bf_xmloff/XMLChartPropertySetMapper.hxx>
+
 #include "queue"
 
 namespace com { namespace sun { namespace star {
@@ -66,7 +68,6 @@ namespace com { namespace sun { namespac
 namespace binfilter {
 
 class SvXMLAutoStylePoolP;
-class XMLChartExportPropertyMapper;
 class SvXMLExport;
 class XMLPropertyHandlerFactory;
 class XMLPropertySetMapper;
