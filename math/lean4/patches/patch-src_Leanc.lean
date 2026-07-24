$NetBSD: patch-src_Leanc.lean,v 1.1 2026/07/24 18:39:20 wiz Exp $

Provide anchor for SUBST_SED, to provide rpath flags.

--- src/Leanc.lean.orig	2026-07-22 17:50:04.000000000 +0000
+++ src/Leanc.lean
@@ -41,6 +41,7 @@ Interesting options:
   let mut cflagsInternal := getInternalCFlags root
   let mut ldflagsInternal := getInternalLinkerFlags root
   let mut ldflags := getLinkerFlags root linkStatic
+  ldflags := ldflags ++ #[@LINKER_FLAGS@]
   if System.Platform.isWindows && !args.contains "-shared" then
     ldflags := ldflags ++ #["-Wl,--whole-archive", "-lleanmanifest", "-Wl,--no-whole-archive"]
 
