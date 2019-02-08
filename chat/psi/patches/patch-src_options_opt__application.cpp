$NetBSD: patch-src_options_opt__application.cpp,v 1.1 2019/02/08 14:56:01 nia Exp $

Make sure the correct proxy.h include is included.

--- src/options/opt_application.cpp.orig	2017-05-24 07:22:55.000000000 +0000
+++ src/options/opt_application.cpp
@@ -2,7 +2,7 @@
 #include "common.h"
 #include "iconwidget.h"
 #include "psioptions.h"
-#include "proxy.h"
+#include "../proxy.h"
 #include "translationmanager.h"
 #include "varlist.h"
 #include "applicationinfo.h"
