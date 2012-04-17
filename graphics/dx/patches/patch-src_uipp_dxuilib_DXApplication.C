$NetBSD: patch-src_uipp_dxuilib_DXApplication.C,v 1.1 2012/04/17 17:44:02 joerg Exp $

--- src/uipp/dxuilib/DXApplication.C.orig	2006-06-22 19:45:34.000000000 +0000
+++ src/uipp/dxuilib/DXApplication.C
@@ -2248,8 +2248,7 @@ void DXApplication::installDefaultResour
     this->setDefaultResources(baseWidget, _defaultDXResources);
     this->IBMApplication::installDefaultResources(baseWidget);
 }
-boolean DXApplication::initialize(unsigned int* argcp,
-								  char**        argv)
+boolean DXApplication::initialize(int* argcp, char** argv)
 {
 	boolean wasSetBusy = FALSE;
 
