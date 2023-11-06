$NetBSD: patch-src_Idris_Package.idr,v 1.1 2023/11/06 17:17:51 pho Exp $

Add DESTDIR support.

TODO: Upstream this

--- src/Idris/Package.idr.orig	2022-10-27 15:43:33.000000000 +0000
+++ src/Idris/Package.idr
@@ -582,7 +582,8 @@ install pkg opts installSrc -- not used 
                                (mainmod pkg)
          wdir <- getWorkingDir
          -- Make the package installation directory
-         let targetDir = prefix_dir (dirs (options defs)) </>
+         let stageDir = fromMaybe "" (stage_dir (dirs (options defs)))
+         let targetDir = stageDir ++ prefix_dir (dirs (options defs)) </>
                              "idris2-" ++ showVersion False version </>
                              installDir pkg
          Right _ <- coreLift $ mkdirAll targetDir
@@ -934,6 +935,7 @@ partitionOpts opts = foldr pOptUpdate (M
     optType (Directive d)          = POpt
     optType (BuildDir f)           = POpt
     optType (OutputDir f)          = POpt
+    optType (StageDir f)           = POpt
     optType WarningsAsErrors       = POpt
     optType HashesInsteadOfModTime = POpt
     optType Profile                = POpt
@@ -966,6 +968,7 @@ errorMsg = unlines
   , "    --directive <directive>"
   , "    --build-dir <dir>"
   , "    --output-dir <dir>"
+  , "    --stage-dir <dir>"
   ]
 
 export
