$NetBSD: patch-libraries_Cabal_Cabal_src_Distribution_Simple_LocalBuildInfo.hs,v 1.1 2025/08/13 10:56:53 pho Exp $

Fix a bug in the rpath handling in Cabal. The upstream has once attempted
to fix it (https://github.com/haskell/cabal/pull/4033) but the fix turned
out to be incomplete.

Suppose a package has internal libraries A and B. B depends on A but
nothing else does. In this case depLibraryPaths erroneously returns the
build directory of A for any components that depend on B. This is because
internalDeps is a list of *direct* internal dependencies while
(installedPkgs lbi) includes indirect ones, so is_external returns False
for indirect dependencies, including A in this case.

The consequence of the bug is that resulting dynamic libraries will contain
rpaths to build directories if they have indirect internal dependencies. In
pkgsrc the bug only rises up to the surface when WRKOBJDIR is set to
somewhere under /tmp, which is why we hadn't noticed its existence for
years. See
https://mail-index.netbsd.org/pkgsrc-users/2025/08/12/msg041867.html

TODO: Upstream this patch. The fix is not pkgsrc-specific at all.

--- libraries/Cabal/Cabal/src/Distribution/Simple/LocalBuildInfo.hs.orig	2025-08-12 18:10:37.229516684 +0000
+++ libraries/Cabal/Cabal/src/Distribution/Simple/LocalBuildInfo.hs
@@ -247,11 +247,9 @@ depLibraryPaths
     let
       -- TODO: this is kind of inefficient
       internalDeps =
-        [ uid
-        | (uid, _) <- componentPackageDeps clbi
-        , -- Test that it's internal
-        sub_target <- allTargetsInBuildOrder' pkgDescr lbi
-        , componentUnitId (targetCLBI (sub_target)) == uid
+        [ installedUnitId ipkg
+        | ipkg <- allPackages installed
+        , Installed.sourcePackageId ipkg == localPackage lbi
         ]
       internalLibs =
         [ getLibDir (targetCLBI sub_target)
