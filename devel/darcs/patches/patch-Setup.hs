$NetBSD: patch-Setup.hs,v 1.1 2022/02/14 14:45:09 pho Exp $

Install the man page to the correct directory. This is pkgsrc-specific.

--- Setup.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ Setup.hs
@@ -9,7 +9,7 @@ import Distribution.Package ( packageVer
 import Distribution.Version( Version )
 import Distribution.Simple.LocalBuildInfo
          ( LocalBuildInfo(..), absoluteInstallDirs )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.Setup
     (buildVerbosity, copyDest, copyVerbosity, fromFlag,
      haddockVerbosity, installVerbosity, replVerbosity )
@@ -87,7 +87,7 @@ installManpage pkg lbi verbosity copy = 
   when have_manpage $
     copyFiles
       verbosity
-      (mandir (absoluteInstallDirs pkg lbi copy) </> "man1")
+      (prefix (absoluteInstallDirs pkg lbi copy) </> "man" </> "man1")
       [(buildDir lbi </> "darcs", "darcs.1")]
 
 -- ---------------------------------------------------------------------
