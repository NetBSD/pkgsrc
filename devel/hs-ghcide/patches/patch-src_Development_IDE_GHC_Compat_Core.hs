$NetBSD: patch-src_Development_IDE_GHC_Compat_Core.hs,v 1.1 2026/11/09 13:49:19 pho Exp $

Fix a build failure on GHC 9.10.3. The change to the return type of
GHCi.loadDLL was backported to the 9.10 branch, which made this #if
conditional incorrect.

While this is technically an upstream bug, we will be upgrading our GHC in
the near future anyway, so the patch isn't really worth upstreaming.

--- src/Development/IDE/GHC/Compat/Core.hs.orig	2026-11-09 13:32:53.302881061 +0000
+++ src/Development/IDE/GHC/Compat/Core.hs
@@ -703,7 +703,7 @@ initObjLinker env =
 loadDLL :: HscEnv -> String -> IO (Maybe String)
 loadDLL env str = do
     res <- GHCi.loadDLL (GHCi.hscInterp env) str
-#if MIN_VERSION_ghc(9,11,0)
+#if MIN_VERSION_ghc(9,10,3)
     pure $
       case res of
         Left err_msg -> Just err_msg
