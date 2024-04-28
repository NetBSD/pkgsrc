$NetBSD: patch-hadrian_src_Settings_Default.hs,v 1.1 2024/04/28 05:58:58 pho Exp $

Do not build haddock with the stage-0 compiler. That's not only pointless
but also impossible in our case because our bootkits in the pre-Hadrian era
lack the xhtml package, which haddock depends on.

Probably not eligible for upstreaming though, because regular GHC
distributions of course have xhtml.

TODO: Try removing this patch and see if it works. I believe none of our
bootkits are from pre-Hadrian era as it is now. (pho)

--- hadrian/src/Settings/Default.hs.orig	2023-01-11 15:35:59.835839905 +0000
+++ hadrian/src/Settings/Default.hs
@@ -86,7 +86,6 @@ stage0Packages = do
              , ghcHeap
              , ghci
              , ghcPkg
-             , haddock
              , hsc2hs
              , hpc
              , hpcBin
