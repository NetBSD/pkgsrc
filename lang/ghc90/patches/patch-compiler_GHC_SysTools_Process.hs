$NetBSD: patch-compiler_GHC_SysTools_Process.hs,v 1.1 2021/05/01 09:04:57 pho Exp $

This is more like pkgsrc-specific than an upstream issue. Unless we
are on Windows, don't use "response file", the @FILE syntax while
invoking CC or LD. Our tool wrappers don't look into response files,
and therefore can't detect mistakes like depending on Cabal packages
that aren't declared as pkgsrc dependency.

The reason why GHC does it is due to some limitation on the length of
argv on Windows. So maybe the patch is worth sending to the upstream.

Note that this patch would break the package if we didn't have its
$ORIGIN use eliminated because our wrappers hate relative rpaths.

--- compiler/GHC/SysTools/Process.hs.orig	2021-05-01 04:49:05.262346202 +0000
+++ compiler/GHC/SysTools/Process.hs
@@ -30,7 +30,9 @@ import System.IO
 import System.IO.Error as IO
 import System.Process
 
+#if defined(mingw32_HOST_OS)
 import GHC.SysTools.FileCleanup
+#endif
 
 -- | Enable process jobs support on Windows if it can be expected to work (e.g.
 -- @process >= 1.6.9.0@).
@@ -141,6 +143,7 @@ runSomethingResponseFile
   :: DynFlags -> (String->String) -> String -> String -> [Option]
   -> Maybe [(String,String)] -> IO ()
 
+#if defined(mingw32_HOST_OS)
 runSomethingResponseFile dflags filter_fn phase_name pgm args mb_env =
     runSomethingWith dflags phase_name pgm args $ \real_args -> do
         fp <- getResponseFile real_args
@@ -183,6 +186,10 @@ runSomethingResponseFile dflags filter_f
             x
         , "\""
         ]
+#else
+runSomethingResponseFile dflags filter_fn phase_name pgm args mb_env =
+    runSomethingFiltered dflags filter_fn phase_name pgm args Nothing mb_env
+#endif
 
 runSomethingFiltered
   :: DynFlags -> (String->String) -> String -> String -> [Option]
