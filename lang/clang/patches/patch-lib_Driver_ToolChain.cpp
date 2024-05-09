$NetBSD: patch-lib_Driver_ToolChain.cpp,v 1.3 2024/05/09 14:15:51 jperkin Exp $

[LLD] Add NetBSD support as a new flavor of LLD (nb.lld)
https://reviews.llvm.org/D70048
Add -R for library paths on SunOS.

--- lib/Driver/ToolChain.cpp.orig	2023-11-28 08:52:28.000000000 +0000
+++ lib/Driver/ToolChain.cpp
@@ -837,6 +837,8 @@ std::string ToolChain::GetLinkerPath(boo
     llvm::SmallString<8> LinkerName;
     if (Triple.isOSDarwin())
       LinkerName.append("ld64.");
+    else if (Triple.isOSNetBSD())
+      LinkerName.append("nb.");
     else
       LinkerName.append("ld.");
     LinkerName.append(UseLinker);
@@ -1213,9 +1215,13 @@ void ToolChain::AddCXXStdlibLibArgs(cons
 
 void ToolChain::AddFilePathLibArgs(const ArgList &Args,
                                    ArgStringList &CmdArgs) const {
-  for (const auto &LibPath : getFilePaths())
-    if(LibPath.length() > 0)
+  for (const auto &LibPath : getFilePaths()) {
+    if(LibPath.length() > 0) {
       CmdArgs.push_back(Args.MakeArgString(StringRef("-L") + LibPath));
+      if (Triple.isOSSolaris())
+        CmdArgs.push_back(Args.MakeArgString(StringRef("-R") + LibPath));
+    }
+  }
 }
 
 void ToolChain::AddCCKextLibArgs(const ArgList &Args,
