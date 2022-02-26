$NetBSD: patch-Setup.hs,v 1.4 2022/02/26 08:07:37 pho Exp $

* Don't hard-code the gmake command (pkgsrc specific).

* Set LD_LIBRARY_PATH while building its standard libraries. This is
  needed when idris is linked dynamically.

* Don't try to invoke git. Cabal packages don't come with .git
  directory.

* Fix build with GHC 8.8

* Install man pages under PKGMANDIR. It's unfortunate that ./Setup has
  no options for changing the directory. The module
  Distribution.Simple.InstallDirs (which provides the function
  "mandir") is a part of GHC, and we also don't want to change its
  default mandir because GHC isn't meant to be used solely within
  pkgsrc.

Be careful not to modify this patch after running "bmake
configure". It will break the patch.

--- Setup.hs.orig	2020-03-18 21:55:00.000000000 +0000
+++ Setup.hs
@@ -42,19 +42,20 @@ import Distribution.Types.UnqualComponen
 (<//>) = (Px.</>)
 idrisCmd local = Px.joinPath $ splitDirectories $ ".." <//> ".." <//> buildDir local <//> "idris" <//> "idris"
 #else
-idrisCmd local = ".." </> ".." </>  buildDir local </>  "idris" </>  "idris"
+idrisCmd local = "@PKGSRC_SETENV@ " ++ "LD_LIBRARY_PATH=" ++ idrisLibPath ++
+                 " DYLD_LIBRARY_PATH=" ++ idrisLibPath ++ " " ++
+                 idrisCmdPath
+   where
+      idrisCmdPath = ".." </> ".." </>  buildDir local </>  "idris" </>  "idris"
+      idrisLibPath = ".." </> ".." </>  buildDir local
 #endif
 
 -- -----------------------------------------------------------------------------
 -- Make Commands
 
 -- use GNU make on FreeBSD
-#if defined(freebsd_HOST_OS) || defined(dragonfly_HOST_OS)\
-    || defined(openbsd_HOST_OS) || defined(netbsd_HOST_OS)
-mymake = "gmake"
-#else
-mymake = "make"
-#endif
+mymake = "@GMAKE@"
+
 make verbosity =
    P.runProgramInvocation verbosity . P.simpleProgramInvocation mymake
 
@@ -117,9 +118,7 @@ idrisClean _ flags _ _ = cleanStdLib
 -- Configure
 
 gitHash :: IO String
-gitHash = do h <- Control.Exception.catch (readProcess "git" ["rev-parse", "--short", "HEAD"] "")
-                  (\e -> let e' = (e :: SomeException) in return "PRE")
-             return $ takeWhile (/= '\n') h
+gitHash = return ""
 
 -- Generate a module that contains extra library directories passed
 -- via command-line to cabal
@@ -287,7 +286,7 @@ idrisInstall verbosity copy pkg local
          makeInstall "rts" target'
 
       installManPage = do
-         let mandest = mandir (L.absoluteInstallDirs pkg local copy) ++ "/man1"
+         let mandest = prefix (L.absoluteInstallDirs pkg local copy) </> "@PKGMANDIR@" </> "man1"
          notice verbosity $ unwords ["Copying man page to", mandest]
          installOrdinaryFiles verbosity mandest [("man", "idris.1")]
 
