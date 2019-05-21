$NetBSD: patch-src_welcomescreen.cpp,v 1.1 2019/05/21 17:44:46 wiz Exp $

Add header for LearnMoreLink.
https://github.com/vslavik/poedit/pull/576

--- src/welcomescreen.cpp.orig	2019-05-20 11:39:34.000000000 +0000
+++ src/welcomescreen.cpp
@@ -26,6 +26,7 @@
 #include "welcomescreen.h"
 
 #include "colorscheme.h"
+#include "customcontrols.h"
 #include "crowdin_gui.h"
 #include "edapp.h"
 #include "edframe.h"
