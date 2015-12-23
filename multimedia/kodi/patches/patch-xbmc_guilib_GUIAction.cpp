$NetBSD: patch-xbmc_guilib_GUIAction.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/guilib/GUIAction.cpp.orig	2015-12-22 18:26:01.000000000 +0000
+++ xbmc/guilib/GUIAction.cpp
@@ -23,6 +23,7 @@
 #include "GUIWindowManager.h"
 #include "GUIControl.h"
 #include "GUIInfoManager.h"
+#include <cstdlib>
 
 using namespace std;
 
