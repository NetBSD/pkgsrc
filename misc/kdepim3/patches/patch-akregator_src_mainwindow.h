$NetBSD: patch-akregator_src_mainwindow.h,v 1.1 2013/03/26 23:30:45 joerg Exp $

--- akregator/src/mainwindow.h.orig	2013-03-26 09:32:12.000000000 +0000
+++ akregator/src/mainwindow.h
@@ -39,8 +39,11 @@ class KActionCollection;
 class KToggleAction;
 class KSqueezedTextLabel;
 class KProgress;
-class KParts::BrowserExtension;
-class KParts::PartManager;
+
+namespace KParts {
+    class BrowserExtension;
+    class PartManager;
+}
 
 namespace KPIM
 {
