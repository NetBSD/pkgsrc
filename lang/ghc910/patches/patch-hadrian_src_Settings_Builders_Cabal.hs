$NetBSD: patch-hadrian_src_Settings_Builders_Cabal.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

Under no circumstances we should build static GHCi objects because:

  1. The only case they need to be built is when we build GHC
     statically. We only do it for bootkits but not for regular
     builds. Bootkits don't need GHCi, so there's no point building them.

  2. We can't build them on Solaris when -fsplit-sections is enabled, which
     we enable. Solaris LD doesn't support linker scripts. Nothing fancy,
     like merging split sections back to their original form, can be done
     with that exotic linker.

This is more like pkgsrc-specific than a genuine defect of the upstream
code, so don't upstream this. There should ideally be a switch, such as
"ghciLibraries :: Bool" in Flavour.Type.Flavour to support our use case,
but... do anyone aside of pkgsrc want it?

--- hadrian/src/Settings/Builders/Cabal.hs.orig	2025-01-27 01:04:45.571870819 +0000
+++ hadrian/src/Settings/Builders/Cabal.hs
@@ -143,7 +143,7 @@ libraryArgs = do
     package     <- getPackage
     withGhci    <- expr ghcWithInterpreter
     dynPrograms <- expr (flavour >>= dynamicGhcPrograms)
-    ghciObjsSupported <- expr platformSupportsGhciObjects
+    let ghciObjsSupported = False
     let ways = Set.insert contextWay flavourWays
         hasVanilla = vanilla `elem` ways
         hasProfiling = any (wayUnit Profiling) ways
