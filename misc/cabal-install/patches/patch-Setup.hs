$NetBSD: patch-Setup.hs,v 1.1 2020/10/13 12:08:10 pho Exp $

Install man pages under PKGMANDIR. It's unfortunate that ./Setup has
no options for changing the directory. The module
Distribution.Simple.InstallDirs is a part of GHC, and we also don't
want to change its default mandir because GHC isn't meant to be used
solely within pkgsrc.

Be careful not to modify this patch after running "bmake
configure". It will break the patch.

--- Setup.hs.orig	2020-10-13 11:50:11.049290780 +0000
+++ Setup.hs
@@ -5,7 +5,7 @@ import Distribution.Simple ( defaultMain
                            , postCopy
                            , postInst
                            )
-import Distribution.Simple.InstallDirs ( mandir
+import Distribution.Simple.InstallDirs ( prefix
                                        , CopyDest (NoCopyDest)
                                        )
 import Distribution.Simple.LocalBuildInfo ( LocalBuildInfo(..)
@@ -59,5 +59,5 @@ buildManpage lbi verbosity = do
 
 installManpage :: PackageDescription -> LocalBuildInfo -> Verbosity -> CopyDest -> IO ()
 installManpage pkg lbi verbosity copy = do
-  let destDir = mandir (absoluteInstallDirs pkg lbi copy) </> "man1"
+  let destDir = prefix (absoluteInstallDirs pkg lbi copy) </> "@PKGMANDIR@" </> "man1"
   installOrdinaryFiles verbosity destDir [(buildDir lbi </> "cabal", "cabal.1")]
