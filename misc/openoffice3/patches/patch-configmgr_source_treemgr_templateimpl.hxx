$NetBSD: patch-configmgr_source_treemgr_templateimpl.hxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- configmgr/source/treemgr/templateimpl.hxx.orig	2012-06-23 17:27:43.000000000 +0000
+++ configmgr/source/treemgr/templateimpl.hxx
@@ -31,6 +31,7 @@
 #ifndef CONFIGMGR_TEMPLATEIMPL_HXX_
 #define CONFIGMGR_TEMPLATEIMPL_HXX_
 
+#include "treemanager.hxx"
 #include "template.hxx"
 #include "configpath.hxx"
 #include "requestoptions.hxx"
