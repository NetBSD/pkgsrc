$NetBSD: patch-Setup.hs,v 1.2 2025/01/31 01:03:47 pho Exp $

Install the man page to the correct directory. This is pkgsrc-specific.

--- Setup.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ Setup.hs
@@ -8,8 +8,8 @@ import Distribution.PackageDescription (
 import Distribution.Package ( packageVersion )
 import Distribution.Version( Version )
 import Distribution.Simple.LocalBuildInfo
-         ( LocalBuildInfo(..), absoluteInstallDirs )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+         ( LocalBuildInfo(..), absoluteInstallDirs, buildDir )
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
