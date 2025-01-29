$NetBSD: patch-libraries_Cabal_Cabal_src_Distribution_Simple_GHC_Build_Link.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

Hunk #0, #1, #2: Revert the change introduced in
  https://github.com/haskell/cabal/issues/1660

  Do not use @rpath on Darwin, instead use the final destination path as a
  library install name. This is pkgsrc-specific.

  See also https://github.com/haskell/cabal/pull/7076 And
  https://github.com/haskell/cabal/issues/7339

Hunk #2: Enable Cabal's rpath overriding functionality on all the platforms
  known to use ELF.

  When a Cabal package which defines both a library and an executable to be
  built, GHC by default embeds an rpath to the *build* directory into the
  executable. This may sound like a bug in GHC but is actually not, because
  GHC doesn't know the fact that the said library is going to be installed
  elsewhere. To overcome this issue, Cabal has a functionality to disable
  the default rpath handling of GHC and construct the correct set of
  rpaths... but only on certain platforms for some reason.

  Pull request: https://github.com/haskell/cabal/pull/7382

--- libraries/Cabal/Cabal/src/Distribution/Simple/GHC/Build/Link.hs.orig	2025-01-09 10:49:52.488968546 +0000
+++ libraries/Cabal/Cabal/src/Distribution/Simple/GHC/Build/Link.hs
@@ -213,7 +213,7 @@ linkLibrary buildTargetDir cleanedExtraL
     ghciLibFilePath = buildTargetDir </> Internal.mkGHCiLibName uid
     ghciProfLibFilePath = buildTargetDir </> Internal.mkGHCiProfLibName uid
     libInstallPath =
-      libdir $
+      dynlibdir $
         absoluteComponentInstallDirs
           pkg_descr
           lbi
@@ -302,7 +302,6 @@ linkLibrary buildTargetDir cleanedExtraL
           -- discussion in #1660.
           ghcOptDylibName =
             if hostOS == OSX
-              && ghcVersion < mkVersion [7, 8]
               then toFlag sharedLibInstallPath
               else mempty
         , ghcOptLinkLibs = extraLibs libBi
@@ -504,15 +503,15 @@ getRPaths pbci = do
     -- 'False', while those operating systems themselves do support RPATH.
     supportRPaths Linux = True
     supportRPaths Windows = False
-    supportRPaths OSX = True
+    supportRPaths OSX = False
     supportRPaths FreeBSD =
       case compid of
         CompilerId GHC ver | ver >= mkVersion [7, 10, 2] -> True
         _ -> False
-    supportRPaths OpenBSD = False
-    supportRPaths NetBSD = False
-    supportRPaths DragonFly = False
-    supportRPaths Solaris = False
+    supportRPaths OpenBSD = True
+    supportRPaths NetBSD = True
+    supportRPaths DragonFly = True
+    supportRPaths Solaris = True
     supportRPaths AIX = False
     supportRPaths HPUX = False
     supportRPaths IRIX = False
