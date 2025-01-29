$NetBSD: patch-compiler_GHC_SysTools_Process.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

This is more like pkgsrc-specific than an upstream issue. Don't use
"response file", the @FILE syntax while invoking CC or LD. Our tool
wrappers don't look into response files, and therefore can't detect
mistakes like depending on Cabal packages that aren't declared as pkgsrc
dependency.

Note that this patch would break GHC if we didn't have its $ORIGIN use
eliminated because our wrappers hate relative rpaths.

--- compiler/GHC/SysTools/Process.hs.orig	2024-05-10 05:05:48.000000000 +0000
+++ compiler/GHC/SysTools/Process.hs
@@ -159,6 +159,7 @@ runSomethingResponseFile
   -> [Option]
   -> Maybe [(String,String)]
   -> IO ()
+#if 0
 runSomethingResponseFile logger tmpfs tmp_dir filter_fn phase_name pgm args mb_env =
     runSomethingWith logger phase_name pgm args $ \real_args -> do
         fp <- getResponseFile real_args
@@ -197,6 +198,10 @@ runSomethingResponseFile logger tmpfs tm
             x
         , "\""
         ]
+#else
+runSomethingResponseFile logger tmpfs dflags filter_fn phase_name pgm args mb_env =
+  runSomethingFiltered logger filter_fn phase_name pgm args Nothing mb_env
+#endif
 
 runSomethingFiltered
   :: Logger -> (String->String) -> String -> String -> [Option]
