$NetBSD: patch-LanguageServer_LanguageServerLogView.h,v 1.1 2022/10/17 16:50:03 andvar Exp $

Reorder <wx/menu.h> to fix build in NetBSD.

--- LanguageServer/LanguageServerLogView.h	2022-05-02 22:26:31.620093956 +0300
+++ LanguageServer/LanguageServerLogView.h
@@ -1,5 +1,6 @@
 #ifndef LANGUAGESERVERLOGVIEW_H
 #define LANGUAGESERVERLOGVIEW_H
+#include <wx/menu.h>
 #include "UI.h"
 
 class LanguageServerLogView : public LanguageServerLogViewBase
