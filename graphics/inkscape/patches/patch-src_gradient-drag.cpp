$NetBSD: patch-src_gradient-drag.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/gradient-drag.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/gradient-drag.cpp
@@ -55,6 +55,8 @@
 #include "ui/control-manager.h"
 #include "ui/tools/tool-base.h"
 
+using std::floor;
+
 using Inkscape::ControlManager;
 using Inkscape::CtrlLineType;
 using Inkscape::DocumentUndo;
