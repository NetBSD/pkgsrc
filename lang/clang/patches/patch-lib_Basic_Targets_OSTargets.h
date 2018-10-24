$NetBSD: patch-lib_Basic_Targets_OSTargets.h,v 1.2 2018/10/24 21:12:59 maya Exp $

Sync SunOS default defines with a working reality.
NetBSD __float128, needed to build anything with base libstdc++
which assumes __float128.

--- lib/Basic/Targets/OSTargets.h.orig	2018-01-04 07:43:41.000000000 +0000
+++ lib/Basic/Targets/OSTargets.h
@@ -358,12 +358,22 @@ protected:
     Builder.defineMacro("__ELF__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
   }
 
 public:
   NetBSDTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
       : OSTargetInfo<Target>(Triple, Opts) {
     this->MCountName = "_mcount";
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
 
@@ -531,20 +541,16 @@ protected:
     Builder.defineMacro("__ELF__");
     Builder.defineMacro("__svr4__");
     Builder.defineMacro("__SVR4");
-    // Solaris headers require _XOPEN_SOURCE to be set to 600 for C99 and
-    // newer, but to 500 for everything else.  feature_test.h has a check to
-    // ensure that you are not using C99 with an old version of X/Open or C89
-    // with a new version.
-    if (Opts.C99)
+    // Compatibility with GCC to satisfy <sys/feature_tests.h> requirements.
+    if (Opts.CPlusPlus) {
+      Builder.defineMacro("__STDC_VERSION__", "199901L");
       Builder.defineMacro("_XOPEN_SOURCE", "600");
-    else
-      Builder.defineMacro("_XOPEN_SOURCE", "500");
-    if (Opts.CPlusPlus)
-      Builder.defineMacro("__C99FEATURES__");
-    Builder.defineMacro("_LARGEFILE_SOURCE");
-    Builder.defineMacro("_LARGEFILE64_SOURCE");
-    Builder.defineMacro("__EXTENSIONS__");
-    Builder.defineMacro("_REENTRANT");
+      Builder.defineMacro("_LARGEFILE_SOURCE");
+      Builder.defineMacro("_LARGEFILE64_SOURCE");
+      Builder.defineMacro("__EXTENSIONS__");
+    }
+    if (Opts.POSIXThreads)
+      Builder.defineMacro("_REENTRANT");
   }
 
 public:
