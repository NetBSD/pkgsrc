$NetBSD: patch-src_lake_Lake_Build_Common.lean,v 1.1 2026/07/24 18:39:20 wiz Exp $

Use linker flags during linking (for rpath).

--- src/lake/Lake/Build/Common.lean.orig	2026-07-22 17:50:04.000000000 +0000
+++ src/lake/Lake/Build/Common.lean
@@ -930,7 +930,7 @@ public def buildSharedLib
     -- and thus need to copied from the cache with that name
     let art ← buildArtifactUnlessUpToDate libFile (ext := sharedLibExt) (restore := true) do
       let libs ← if linkDeps then mkLinkOrder libs else pure #[]
-      let args := mkLinkObjArgs objs libs ++ weakArgs ++ traceArgs
+      let args := mkLinkObjArgs objs libs ++ #[@LINKER_FLAGS@] ++ weakArgs ++ traceArgs
       compileSharedLib libFile args linker
     return {name := libName, path := art.path, deps := libs, plugin}
 
@@ -955,7 +955,7 @@ public def buildLeanSharedLib
       let lean ← getLeanInstall
       let libs ← if linkDeps then mkLinkOrder libs else pure #[]
       let args := mkLinkObjArgs objs libs ++ weakArgs ++ traceArgs ++
-        #["-L", lean.leanLibDir.toString] ++ lean.ccLinkSharedFlags
+        #["-L", lean.leanLibDir.toString] ++ #[@LINKER_FLAGS@] ++ lean.ccLinkSharedFlags
       compileSharedLib libFile args lean.cc
     return {name := libName, path := art.path, deps := libs, plugin}
 
@@ -977,6 +977,6 @@ public def buildLeanExe
       let lean ← getLeanInstall
       let libs ← mkLinkOrder libs
       let args := mkLinkObjArgs objs libs ++ weakArgs ++ traceArgs ++
-        #["-L", lean.leanLibDir.toString] ++ lean.ccLinkFlags sharedLean
+        #["-L", lean.leanLibDir.toString] ++ #[@LINKER_FLAGS@] ++ lean.ccLinkFlags sharedLean
       compileExe exeFile args lean.cc
     return art.path
