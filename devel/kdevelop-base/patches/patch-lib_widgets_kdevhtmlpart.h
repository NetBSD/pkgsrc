$NetBSD: patch-lib_widgets_kdevhtmlpart.h,v 1.1 2013/03/26 23:30:44 joerg Exp $

--- lib/widgets/kdevhtmlpart.h.orig	2013-03-25 20:32:56.000000000 +0000
+++ lib/widgets/kdevhtmlpart.h
@@ -14,7 +14,9 @@ Customized KHTML part for KDevelop.
 
 class KAction;
 class KToolBarPopupAction;
-class KParts::ReadOnlyPart;
+namespace KParts {
+class ReadOnlyPart;
+}
 
 struct DocumentationHistoryEntry {
     KURL url;
