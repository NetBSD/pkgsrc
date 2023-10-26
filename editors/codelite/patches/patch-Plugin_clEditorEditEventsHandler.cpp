$NetBSD: patch-Plugin_clEditorEditEventsHandler.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxTheApp

--- Plugin/clEditorEditEventsHandler.cpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ Plugin/clEditorEditEventsHandler.cpp
@@ -2,6 +2,7 @@
 
 #include "event_notifier.h"
 
+#include <wx/app.h>
 #include <wx/combobox.h>
 #include <wx/stc/stc.h>
 #include <wx/textctrl.h>
