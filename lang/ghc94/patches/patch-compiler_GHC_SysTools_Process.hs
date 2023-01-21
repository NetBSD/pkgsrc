$NetBSD: patch-compiler_GHC_SysTools_Process.hs,v 1.1 2023/01/21 04:49:25 pho Exp $

This is more like pkgsrc-specific than an upstream issue. Unless we
are on Windows, don't use "response file", the @FILE syntax while
invoking CC or LD. Our tool wrappers don't look into response files,
and therefore can't detect mistakes like depending on Cabal packages
that aren't declared as pkgsrc dependency.

Note that this patch would break GHC if we didn't have its $ORIGIN use
eliminated because our wrappers hate relative rpaths.

--- compiler/GHC/SysTools/Process.hs.orig	2022-12-23 16:19:02.000000000 +0000
+++ compiler/GHC/SysTools/Process.hs
@@ -160,6 +160,7 @@ runSomethingResponseFile
   -> [Option]
   -> Maybe [(String,String)]
   -> IO ()
+#if defined(mingw32_HOST_OS)
 runSomethingResponseFile logger tmpfs dflags filter_fn phase_name pgm args mb_env =
     runSomethingWith logger phase_name pgm args $ \real_args -> do
         fp <- getResponseFile real_args
@@ -198,6 +199,10 @@ runSomethingResponseFile logger tmpfs df
             x
         , "\""
         ]
+#else
+runSomethingResponseFile logger tmpfs dflags filter_fn phase_name pgm args mb_env =
+  runSomethingFiltered logger filter_fn phase_name pgm args Nothing mb_env
+#endif
 
 runSomethingFiltered
   :: Logger -> (String->String) -> String -> String -> [Option]
