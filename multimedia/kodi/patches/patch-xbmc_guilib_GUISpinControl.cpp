$NetBSD: patch-xbmc_guilib_GUISpinControl.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/guilib/GUISpinControl.cpp.orig	2015-12-22 18:27:35.000000000 +0000
+++ xbmc/guilib/GUISpinControl.cpp
@@ -22,6 +22,7 @@
 #include "input/Key.h"
 #include "utils/StringUtils.h"
 #include <stdio.h>
+#include <cstdlib>
 
 using namespace std;
 
