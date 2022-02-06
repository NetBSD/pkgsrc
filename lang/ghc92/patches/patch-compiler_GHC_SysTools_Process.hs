$NetBSD: patch-compiler_GHC_SysTools_Process.hs,v 1.1 2022/02/06 05:36:16 pho Exp $

This is more like pkgsrc-specific than an upstream issue. Unless we
are on Windows, don't use "response file", the @FILE syntax while
invoking CC or LD. Our tool wrappers don't look into response files,
and therefore can't detect mistakes like depending on Cabal packages
that aren't declared as pkgsrc dependency.

The reason why GHC does it is due to some limitation on the length of
argv on Windows. So maybe the patch is worth sending to the upstream.

Note that this patch would break GHC if we didn't have its $ORIGIN use
eliminated because our wrappers hate relative rpaths.

--- compiler/GHC/SysTools/Process.hs.orig	2021-10-28 20:41:34.000000000 +0000
+++ compiler/GHC/SysTools/Process.hs
@@ -163,6 +163,7 @@ runSomethingResponseFile
   -> [Option]
   -> Maybe [(String,String)]
   -> IO ()
+#if defined(mingw32_HOST_OS)
 runSomethingResponseFile logger tmpfs dflags filter_fn phase_name pgm args mb_env =
     runSomethingWith logger dflags phase_name pgm args $ \real_args -> do
         fp <- getResponseFile real_args
@@ -205,6 +206,10 @@ runSomethingResponseFile logger tmpfs df
             x
         , "\""
         ]
+#else
+runSomethingResponseFile logger tmpfs dflags filter_fn phase_name pgm args mb_env =
+  runSomethingFiltered logger dflags filter_fn phase_name pgm args Nothing mb_env
+#endif
 
 runSomethingFiltered
   :: Logger -> DynFlags -> (String->String) -> String -> String -> [Option]
