$NetBSD: patch-src_runtime_kwalletd_kwalletwizard.cpp,v 1.1 2017/09/23 11:58:37 tnn Exp $

uses boost::shared_ptr

--- src/runtime/kwalletd/kwalletwizard.cpp.orig	2016-08-07 13:59:41.000000000 +0000
+++ src/runtime/kwalletd/kwalletwizard.cpp
@@ -22,6 +22,7 @@
 #include "ui_kwalletwizardpageoptions.h"
 #include "ui_kwalletwizardpagepassword.h"
 #ifdef HAVE_QGPGME
+#include <boost/shared_ptr.hpp>
 #include "ui_kwalletwizardpagepasswordgpg.h"
 #include "ui_kwalletwizardpagegpgkey.h"
 #endif
