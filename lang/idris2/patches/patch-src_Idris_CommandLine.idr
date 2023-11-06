$NetBSD: patch-src_Idris_CommandLine.idr,v 1.1 2023/11/06 17:17:51 pho Exp $

Add DESTDIR support.

TODO: Upstream this

--- src/Idris/CommandLine.idr.orig	2022-10-27 15:43:33.000000000 +0000
+++ src/Idris/CommandLine.idr
@@ -84,6 +84,8 @@ data CLOpt
   BuildDir String |
    ||| Set output directory
   OutputDir String |
+   ||| Set staged installation directory
+  StageDir String |
    ||| Generate profile data when compiling (backend dependent)
   Profile |
    ||| Display Idris version
@@ -240,6 +242,8 @@ options = [MkOpt ["--check", "-c"] [] [C
               (Just $ "Set build directory"),
            MkOpt ["--output-dir"] [Required "dir"] (\d => [OutputDir d])
               (Just $ "Set output directory"),
+           MkOpt ["--stage-dir"] [Required "dir"] (\d => [StageDir d])
+              (Just $ "Set staged installation directory"),
            MkOpt ["--profile"] [] [Profile]
               (Just "Generate profile data when compiling, if supported"),
 
