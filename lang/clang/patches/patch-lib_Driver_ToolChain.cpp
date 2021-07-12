$NetBSD: patch-lib_Driver_ToolChain.cpp,v 1.2 2021/07/12 18:42:06 adam Exp $

[LLD] Add NetBSD support as a new flavor of LLD (nb.lld)
https://reviews.llvm.org/D70048

--- lib/Driver/ToolChain.cpp.orig	2019-07-11 19:06:38.000000000 +0000
+++ lib/Driver/ToolChain.cpp
@@ -506,6 +506,8 @@ std::string ToolChain::GetLinkerPath() c
     llvm::SmallString<8> LinkerName;
     if (Triple.isOSDarwin())
       LinkerName.append("ld64.");
+    else if (Triple.isOSNetBSD())
+      LinkerName.append("nb.");
     else
       LinkerName.append("ld.");
     LinkerName.append(UseLinker);
