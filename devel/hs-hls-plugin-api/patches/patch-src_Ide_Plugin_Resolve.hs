$NetBSD: patch-src_Ide_Plugin_Resolve.hs,v 1.1 2024/05/04 10:42:24 pho Exp $

Upgrade to latest lsp / lsp-types / lsp-test
https://github.com/haskell/haskell-language-server/pull/4166

--- src/Ide/Plugin/Resolve.hs.orig	2024-05-04 10:37:07.495340141 +0000
+++ src/Ide/Plugin/Resolve.hs
@@ -1,6 +1,5 @@
 {-# LANGUAGE DisambiguateRecordFields #-}
 {-# LANGUAGE LambdaCase               #-}
-{-# LANGUAGE OverloadedLabels         #-}
 {-# LANGUAGE OverloadedStrings        #-}
 {-| This module currently includes helper functions to provide fallback support
 to code actions that use resolve in HLS. The difference between the two
@@ -26,7 +25,6 @@ import           Control.Monad.Trans.Exc
 
 import qualified Data.Aeson                    as A
 import           Data.Maybe                    (catMaybes)
-import           Data.Row                      ((.!))
 import qualified Data.Text                     as T
 import           GHC.Generics                  (Generic)
 import           Ide.Logger
@@ -190,7 +188,7 @@ supportsCodeActionResolve :: ClientCapab
 supportsCodeActionResolve caps =
     caps ^? L.textDocument . _Just . L.codeAction . _Just . L.dataSupport . _Just == Just True
     && case caps ^? L.textDocument . _Just . L.codeAction . _Just . L.resolveSupport . _Just of
-        Just row -> "edit" `elem` row .! #properties
+        Just ClientCodeActionResolveOptions{_properties} -> "edit" `elem` _properties
         _        -> False
 
 internalError :: T.Text -> PluginError
