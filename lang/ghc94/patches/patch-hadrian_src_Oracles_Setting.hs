$NetBSD: patch-hadrian_src_Oracles_Setting.hs,v 1.2 2023/01/21 12:02:49 pho Exp $

Hadrian's idea of rpath usability is overly pessimistic. If it's an ELF or
a Mach-O target we should assume it supports rpaths.

Merge request: https://gitlab.haskell.org/ghc/ghc/-/merge_requests/9767

--- hadrian/src/Oracles/Setting.hs.orig	2023-01-15 17:18:47.276886521 +0000
+++ hadrian/src/Oracles/Setting.hs
@@ -269,20 +269,28 @@ anyTargetArch = matchSetting TargetArch
 anyHostOs :: [String] -> Action Bool
 anyHostOs = matchSetting HostOs
 
--- | Check whether the target OS uses the ELF object format.
-isElfTarget :: Action Bool
-isElfTarget = anyTargetOs
+-- | List of OSes that use the ELF object format.
+elfOSes :: [String]
+elfOSes =
     [ "linux", "freebsd", "dragonfly", "openbsd", "netbsd", "solaris2", "kfreebsdgnu"
     , "haiku", "linux-android"
     ]
 
+-- | List of OSes that use the Mach-O object format.
+machoOSes :: [String]
+machoOSes = [ "darwin" ]
+
+-- | Check whether the target OS uses the ELF object format.
+isElfTarget :: Action Bool
+isElfTarget = anyTargetOs elfOSes
+
 -- | Check whether the host OS supports the @-rpath@ linker option when
 -- using dynamic linking.
 --
 -- TODO: Windows supports lazy binding (but GHC doesn't currently support
 --       dynamic way on Windows anyways).
 hostSupportsRPaths :: Action Bool
-hostSupportsRPaths = anyHostOs ["linux", "darwin", "freebsd"]
+hostSupportsRPaths = anyHostOs (elfOSes ++ machoOSes)
 
 -- | Check whether the target supports GHCi.
 ghcWithInterpreter :: Action Bool
