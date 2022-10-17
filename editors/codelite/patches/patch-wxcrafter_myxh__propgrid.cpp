$NetBSD: patch-wxcrafter_myxh__propgrid.cpp,v 1.1 2022/10/17 16:50:04 andvar Exp $

Fix from upstream: SetSplitterLeft was internal function in wxWidgets and became protected.

--- wxcrafter/myxh_propgrid.cpp.orig	2022-04-18 08:09:00.000000000 +0300
+++ wxcrafter/myxh_propgrid.cpp
@@ -48,7 +48,7 @@ wxObject* MyWxPropGridXmlHandler::DoCrea
 
         // add the splitter property after the children were added
         int splitterLeft = GetBool("splitterleft");
-        if(splitterLeft) { m_pgmgr->GetPage(0)->SetSplitterLeft(); }
+        if(splitterLeft) { m_pgmgr->SetSplitterLeft(); }
 
         int splitterPos = GetLong("splitterpos", wxNOT_FOUND);
         if(splitterPos != wxNOT_FOUND) { m_pgmgr->GetPage(0)->SetSplitterPosition(splitterPos); }
