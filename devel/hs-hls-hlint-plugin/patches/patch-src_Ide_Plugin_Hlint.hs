$NetBSD: patch-src_Ide_Plugin_Hlint.hs,v 1.1 2023/01/31 18:59:48 pho Exp $

Fix build with apply-refact-0.12.

--- src/Ide/Plugin/Hlint.hs.orig	2023-01-31 18:52:13.392202043 +0000
+++ src/Ide/Plugin/Hlint.hs
@@ -594,7 +594,7 @@ applyHint recorder ide nfp mhint =
             -- We have to reparse extensions to remove the invalid ones
             let (enabled, disabled, _invalid) = Refact.parseExtensions $ map show exts
             let refactExts = map show $ enabled ++ disabled
-            (Right <$> withRuntimeLibdir (Refact.applyRefactorings position commands temp refactExts))
+            (Right <$> Refact.applyRefactorings (topDir dflags) position commands temp refactExts)
                 `catches` errorHandlers
 #else
     mbParsedModule <- liftIO $ runAction' $ getParsedModuleWithComments nfp
