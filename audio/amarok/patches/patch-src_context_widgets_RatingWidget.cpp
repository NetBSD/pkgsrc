$NetBSD: patch-src_context_widgets_RatingWidget.cpp,v 1.1 2012/03/20 10:28:29 markd Exp $

--- src/context/widgets/RatingWidget.cpp.orig	2011-12-15 07:36:48.000000000 +0000
+++ src/context/widgets/RatingWidget.cpp
@@ -39,7 +39,7 @@
 #include <klocale.h>
 #include <kstandarddirs.h>
 
-using namespace Amarok;
+// using namespace Amarok;
 
 class RatingWidget::Private
 {
