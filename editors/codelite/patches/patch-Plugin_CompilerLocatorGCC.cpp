$NetBSD: patch-Plugin_CompilerLocatorGCC.cpp,v 1.1 2024/02/05 14:32:25 nros Exp $

Codelite generates gmake Makefiles, so use pkgsrc gmake to make
them build correctly

--- Plugin/CompilerLocatorGCC.cpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ Plugin/CompilerLocatorGCC.cpp
@@ -161,12 +161,11 @@ void CompilerLocatorGCC::AddTools(Compil
 #endif
     toolFile.SetFullName("gcc");
     AddTool(compiler, "CC", toolFile.GetFullPath(), suffix);
-    toolFile.SetFullName("make");
     wxString makeExtraArgs;
     if(wxThread::GetCPUCount() > 1) {
         makeExtraArgs << "-j" << wxThread::GetCPUCount();
     }
-    AddTool(compiler, "MAKE", toolFile.GetFullPath(), "", makeExtraArgs);
+    AddTool(compiler, "MAKE", "gmake", "", makeExtraArgs);
 
     // ++++-----------------------------------------------------------------
     // From this point on, we use /usr/bin only
