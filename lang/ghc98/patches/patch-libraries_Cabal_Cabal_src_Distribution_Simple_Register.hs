$NetBSD: patch-libraries_Cabal_Cabal_src_Distribution_Simple_Register.hs,v 1.2 2024/05/12 05:09:57 pho Exp $

Fix a long-standing Cabal bug: when a package to be built contains a
library that has no Haskell modules, "./Setup register" tries to register
the library with fields "haddock-interfaces:" and "haddock-html:" pointing
at non-existent files or directories, and "ghc-pkg register" warns about
them.

wiz@ asked me three times about these suspicious yet harmless warnings and
I kept telling him to just ignore them. I was lazy (as always) and
repeatedly said something like "oh yeah I'll fix it some time in the
future" but now the future has finally come! (pho@)

https://github.com/haskell/cabal/pull/9997

--- libraries/Cabal/Cabal/src/Distribution/Simple/Register.hs.orig	2024-04-28 14:54:00.713517045 +0000
+++ libraries/Cabal/Cabal/src/Distribution/Simple/Register.hs
@@ -445,8 +445,8 @@ generalInstalledPackageInfo adjustRelInc
     IPI.ldOptions          = ldOptions bi,
     IPI.frameworks         = frameworks bi,
     IPI.frameworkDirs      = extraFrameworkDirs bi,
-    IPI.haddockInterfaces  = [haddockdir installDirs </> haddockName pkg],
-    IPI.haddockHTMLs       = [htmldir installDirs],
+    IPI.haddockInterfaces  = [ haddockdir installDirs </> haddockName pkg | hasModules ],
+    IPI.haddockHTMLs       = [ htmldir installDirs | hasModules ],
     IPI.pkgRoot            = Nothing,
     IPI.libVisibility      = libVisibility lib
   }
