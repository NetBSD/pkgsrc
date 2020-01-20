$NetBSD: patch-Setup.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

* Don't hard-code the gmake command (pkgsrc specific).

* Set LD_LIBRARY_PATH while building its standard libraries. This is
  needed because we link idris dynamically.

* Don't try to invoke git. Cabal packages don't come with .git
  directory.

* Fix build with GHC 8.8

--- Setup.hs.orig	2019-07-22 10:47:26.000000000 +0000
+++ Setup.hs
@@ -42,19 +42,19 @@ import Distribution.Types.UnqualComponen
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
 
--- use GNU make on FreeBSD
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
 
@@ -117,9 +117,7 @@ idrisClean _ flags _ _ = cleanStdLib
 -- Configure
 
 gitHash :: IO String
-gitHash = do h <- Control.Exception.catch (readProcess "git" ["rev-parse", "--short", "HEAD"] "")
-                  (\e -> let e' = (e :: SomeException) in return "PRE")
-             return $ takeWhile (/= '\n') h
+gitHash = return ""
 
 -- Generate a module that contains extra library directories passed
 -- via command-line to cabal
@@ -215,6 +213,7 @@ idrisConfigure _ flags pkgdesc local = d
       autogenComponentModulesDir lbi _ = autogenModulesDir lbi
 #endif
 
+#if !MIN_VERSION_Cabal(3,0,0)
 idrisPreSDist args flags = do
   let dir = S.fromFlag (S.sDistDirectory flags)
   let verb = S.fromFlag (S.sDistVerbosity flags)
@@ -244,6 +243,7 @@ idrisPostSDist args flags desc lbi = do
                               removeFile targetFile)
              (\e -> let e' = (e :: SomeException) in return ())
   postSDist simpleUserHooks args flags desc lbi
+#endif
 
 #if !(MIN_VERSION_Cabal(2,0,0))
 rewriteFileEx :: Verbosity -> FilePath -> String -> IO ()
@@ -353,8 +353,10 @@ main = defaultMainWithHooks $ simpleUser
    , postInst = \_ flags pkg local ->
                   idrisInstall (S.fromFlag $ S.installVerbosity flags)
                                NoCopyDest pkg local
+#if !MIN_VERSION_Cabal(3,0,0)
    , preSDist = idrisPreSDist
    , sDistHook = idrisSDist (sDistHook simpleUserHooks)
    , postSDist = idrisPostSDist
+#endif
    , testHook = idrisTestHook
    }
