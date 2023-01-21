$NetBSD: patch-hadrian_src_Settings_Packages.hs,v 1.1 2023/01/21 04:49:25 pho Exp $

Don't assume we always build the threaded RTS. Not upstreamed yet.

--- hadrian/src/Settings/Packages.hs.orig	2023-01-11 04:48:46.860292356 +0000
+++ hadrian/src/Settings/Packages.hs
@@ -387,7 +387,8 @@ rtsPackageArgs = package rts ? do
 
     mconcat
         [ builder (Cabal Flags) ? mconcat
-          [ any (wayUnit Profiling) rtsWays `cabalFlag` "profiling"
+          [ any (wayUnit Threaded) rtsWays  `cabalFlag` "threaded"
+          , any (wayUnit Profiling) rtsWays `cabalFlag` "profiling"
           , any (wayUnit Debug) rtsWays     `cabalFlag` "debug"
           , any (wayUnit Dynamic) rtsWays   `cabalFlag` "dynamic"
           , useSystemFfi                    `cabalFlag` "use-system-libffi"
