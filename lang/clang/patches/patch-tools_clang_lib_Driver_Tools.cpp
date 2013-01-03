$NetBSD: patch-tools_clang_lib_Driver_Tools.cpp,v 1.3 2013/01/03 15:19:53 adam Exp $

* DragonFly no longer has gcc 4.1 in base, so clang stopped working.
  We prefer to use gcc 4.7 if available due to a better libstdc++.
  The fallback is gcc 4.4 which has been available for several years.
  The libgcc specs are different between 4.4 and 4.7
* DragonFly: Removed duplicate libgcc handling
* DragonFly: Removed redundant rpath-link
* DragonFly: Added -export-dynamic (matches gcc dumpspecs)
* DragonFly: Added gnu-hash to shared objects

--- tools/clang/lib/Driver/Tools.cpp.orig	2012-11-21 07:56:23.000000000 +0000
+++ tools/clang/lib/Driver/Tools.cpp
@@ -6238,21 +6238,28 @@ void dragonfly::Link::ConstructJob(Compi
                                    const InputInfoList &Inputs,
                                    const ArgList &Args,
                                    const char *LinkingOutput) const {
+  bool UseGCC47;
   const Driver &D = getToolChain().getDriver();
   ArgStringList CmdArgs;
 
+  llvm::sys::fs::exists("/usr/lib/gcc47", UseGCC47);
+
   if (!D.SysRoot.empty())
     CmdArgs.push_back(Args.MakeArgString("--sysroot=" + D.SysRoot));
 
+  CmdArgs.push_back("--eh-frame-hdr");
   if (Args.hasArg(options::OPT_static)) {
     CmdArgs.push_back("-Bstatic");
   } else {
+    if (Args.hasArg(options::OPT_rdynamic))
+      CmdArgs.push_back("-export-dynamic");
     if (Args.hasArg(options::OPT_shared))
       CmdArgs.push_back("-Bshareable");
     else {
       CmdArgs.push_back("-dynamic-linker");
       CmdArgs.push_back("/usr/libexec/ld-elf.so.2");
     }
+    CmdArgs.push_back("--hash-style=both");
   }
 
   // When building 32-bit code on DragonFly/pc64, we have to explicitly
@@ -6272,18 +6279,26 @@ void dragonfly::Link::ConstructJob(Compi
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
     if (!Args.hasArg(options::OPT_shared)) {
-      CmdArgs.push_back(
-            Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
-      CmdArgs.push_back(
-            Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
-      CmdArgs.push_back(
-            Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
-    } else {
-      CmdArgs.push_back(
-            Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
-      CmdArgs.push_back(
-            Args.MakeArgString(getToolChain().GetFilePath("crtbeginS.o")));
+      if (Args.hasArg(options::OPT_pg))
+        CmdArgs.push_back(Args.MakeArgString(
+                                getToolChain().GetFilePath("gcrt1.o")));
+      else {
+        if (Args.hasArg(options::OPT_pie))
+          CmdArgs.push_back(Args.MakeArgString(
+                                  getToolChain().GetFilePath("Scrt1.o")));
+        else
+          CmdArgs.push_back(Args.MakeArgString(
+                                  getToolChain().GetFilePath("crt1.o")));
+      }
     }
+    CmdArgs.push_back(Args.MakeArgString(
+                            getToolChain().GetFilePath("crti.o")));
+    if (Args.hasArg(options::OPT_shared) || Args.hasArg(options::OPT_pie))
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crtbeginS.o")));
+    else    
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crtbegin.o")));
   }
 
   Args.AddAllArgs(CmdArgs, options::OPT_L);
@@ -6296,20 +6311,19 @@ void dragonfly::Link::ConstructJob(Compi
       !Args.hasArg(options::OPT_nodefaultlibs)) {
     // FIXME: GCC passes on -lgcc, -lgcc_pic and a whole lot of
     //         rpaths
-    CmdArgs.push_back("-L/usr/lib/gcc41");
+    if (UseGCC47)
+      CmdArgs.push_back("-L/usr/lib/gcc47");
+    else
+      CmdArgs.push_back("-L/usr/lib/gcc44");
 
     if (!Args.hasArg(options::OPT_static)) {
-      CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib/gcc41");
-
-      CmdArgs.push_back("-rpath-link");
-      CmdArgs.push_back("/usr/lib/gcc41");
-
-      CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib");
-
-      CmdArgs.push_back("-rpath-link");
-      CmdArgs.push_back("/usr/lib");
+      if (UseGCC47) {
+        CmdArgs.push_back("-rpath");
+        CmdArgs.push_back("/usr/lib/gcc47");
+      } else {
+        CmdArgs.push_back("-rpath");
+        CmdArgs.push_back("/usr/lib/gcc44");
+      }
     }
 
     if (D.CCCIsCXX) {
@@ -6317,13 +6331,6 @@ void dragonfly::Link::ConstructJob(Compi
       CmdArgs.push_back("-lm");
     }
 
-    if (Args.hasArg(options::OPT_shared)) {
-      CmdArgs.push_back("-lgcc_pic");
-    } else {
-      CmdArgs.push_back("-lgcc");
-    }
-
-
     if (Args.hasArg(options::OPT_pthread))
       CmdArgs.push_back("-lpthread");
 
@@ -6331,23 +6338,42 @@ void dragonfly::Link::ConstructJob(Compi
       CmdArgs.push_back("-lc");
     }
 
-    if (Args.hasArg(options::OPT_shared)) {
-      CmdArgs.push_back("-lgcc_pic");
+    if (UseGCC47) {
+      if (Args.hasArg(options::OPT_static) ||
+          Args.hasArg(options::OPT_static_libgcc)) {
+        CmdArgs.push_back("-lgcc");
+        CmdArgs.push_back("-lgcc_eh");
+      } else {
+        if (Args.hasArg(options::OPT_shared_libgcc)) {
+          CmdArgs.push_back("-lgcc_pic");
+          if (!Args.hasArg(options::OPT_shared))
+            CmdArgs.push_back("-lgcc");
+        } else {
+          CmdArgs.push_back("-lgcc");
+          CmdArgs.push_back("--as-needed");
+          CmdArgs.push_back("-lgcc_pic");
+          CmdArgs.push_back("--no-as-needed");
+        }
+      }
     } else {
-      CmdArgs.push_back("-lgcc");
+      if (Args.hasArg(options::OPT_shared)) {
+        CmdArgs.push_back("-lgcc_pic");
+      } else {
+        CmdArgs.push_back("-lgcc");
+      }
     }
   }
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-    if (!Args.hasArg(options::OPT_shared))
+    if (Args.hasArg(options::OPT_shared) || Args.hasArg(options::OPT_pie))
       CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crtend.o")));
+                              getToolChain().GetFilePath("crtendS.o")));
     else
       CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crtendS.o")));
+                              getToolChain().GetFilePath("crtend.o")));
     CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crtn.o")));
+                            getToolChain().GetFilePath("crtn.o")));
   }
 
   addProfileRT(getToolChain(), Args, CmdArgs, getToolChain().getTriple());
