$NetBSD: patch-src_Idris_SetOptions.idr,v 1.1 2023/11/06 17:17:51 pho Exp $

Add DESTDIR support.

TODO: Upstream this

--- src/Idris/SetOptions.idr.orig	2022-10-27 15:43:33.000000000 +0000
+++ src/Idris/SetOptions.idr
@@ -362,6 +362,9 @@ preOptions (BuildDir d :: opts)
 preOptions (OutputDir d :: opts)
     = do setOutputDir (Just d)
          preOptions opts
+preOptions (StageDir d :: opts)
+    = do setStageDir (Just d)
+         preOptions opts
 preOptions (Directory d :: opts)
     = do defs <- get Ctxt
          dirOption (dirs (options defs)) d
