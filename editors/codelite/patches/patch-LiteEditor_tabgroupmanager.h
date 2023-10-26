$NetBSD: patch-LiteEditor_tabgroupmanager.h,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxXmlNode

--- LiteEditor/tabgroupmanager.h.orig	2023-10-22 11:38:56.025877281 +0000
+++ LiteEditor/tabgroupmanager.h
@@ -33,6 +33,7 @@
 #include <wx/arrstr.h>
 #include <wx/event.h>
 #include <wx/string.h>
+#include <wx/xml/xml.h>
 
 /**
  * Each pair consists of the tabgroup name, and an array of the names of the constituent tabs
