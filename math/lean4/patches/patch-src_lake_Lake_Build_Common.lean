$NetBSD: patch-src_lake_Lake_Build_Common.lean,v 1.2 2026/08/11 12:55:48 wiz Exp $

Use linker flags during linking (for rpath).

--- src/lake/Lake/Build/Common.lean.orig	2026-08-03 09:21:21.000000000 +0000
+++ src/lake/Lake/Build/Common.lean
@@ -937,7 +937,7 @@ -/
 : JobM (Array String) := do
   let lean ← getLeanInstall
   let baseArgs ← mkLinkArgs objs libs linkDeps
-  return baseArgs ++ args ++ #["-L", lean.leanLibDir.toString] ++ lean.ccLinkFlags sharedLean
+  return baseArgs ++ args ++ #["-L", lean.leanLibDir.toString] ++ #[@LINKER_FLAGS@] ++ lean.ccLinkFlags sharedLean
 
 /--
 Build a shared library using `linker`.
