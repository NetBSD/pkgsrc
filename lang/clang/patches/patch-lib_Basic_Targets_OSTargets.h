$NetBSD: patch-lib_Basic_Targets_OSTargets.h,v 1.4 2019/10/19 13:54:29 adam Exp $

Sync SunOS default defines with a working reality.
NetBSD __float128, needed to build anything with base libstdc++
which assumes __float128.

--- lib/Basic/Targets/OSTargets.h.orig	2019-08-01 08:49:35.000000000 +0000
+++ lib/Basic/Targets/OSTargets.h
@@ -436,12 +436,22 @@ protected:
     Builder.defineMacro("__ELF__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
   }
 
 public:
   NetBSDTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
       : OSTargetInfo<Target>(Triple, Opts) {
     this->MCountName = "__mcount";
+    switch (Triple.getArch()) {
+    default:
+      break;
+    case llvm::Triple::x86:
+    case llvm::Triple::x86_64:
+      this->HasFloat128 = true;
+      break;
+    }
   }
 };
 
@@ -610,22 +620,15 @@ protected:
     Builder.defineMacro("__ELF__");
     Builder.defineMacro("__svr4__");
     Builder.defineMacro("__SVR4");
-    // Solaris headers require _XOPEN_SOURCE to be set to 600 for C99 and
-    // newer, but to 500 for everything else.  feature_test.h has a check to
-    // ensure that you are not using C99 with an old version of X/Open or C89
-    // with a new version.
-    if (Opts.C99)
-      Builder.defineMacro("_XOPEN_SOURCE", "600");
-    else
-      Builder.defineMacro("_XOPEN_SOURCE", "500");
+    // Compatibility with GCC to satisfy <sys/feature_tests.h> requirements.
     if (Opts.CPlusPlus) {
-      Builder.defineMacro("__C99FEATURES__");
+      Builder.defineMacro("__STDC_VERSION__", "199901L");
+      Builder.defineMacro("_XOPEN_SOURCE", "600");
       Builder.defineMacro("_FILE_OFFSET_BITS", "64");
+      Builder.defineMacro("_LARGEFILE_SOURCE");
+      Builder.defineMacro("_LARGEFILE64_SOURCE");
+      Builder.defineMacro("__EXTENSIONS__");
     }
-    // GCC restricts the next two to C++.
-    Builder.defineMacro("_LARGEFILE_SOURCE");
-    Builder.defineMacro("_LARGEFILE64_SOURCE");
-    Builder.defineMacro("__EXTENSIONS__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
     if (this->HasFloat128)
