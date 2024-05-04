$NetBSD: patch-src_Development_IDE_Core_PositionMapping.hs,v 1.1 2024/05/04 11:24:53 pho Exp $

Upgrade to latest lsp / lsp-types / lsp-test
https://github.com/haskell/haskell-language-server/pull/4166

--- src/Development/IDE/Core/PositionMapping.hs.orig	2024-05-04 11:00:42.359853887 +0000
+++ src/Development/IDE/Core/PositionMapping.hs
@@ -1,4 +1,3 @@
-{-# LANGUAGE OverloadedLabels #-}
 -- Copyright (c) 2019 The DAML Authors. All rights reserved.
 -- SPDX-License-Identifier: Apache-2.0
 module Development.IDE.Core.PositionMapping
@@ -25,6 +24,7 @@ module Development.IDE.Core.PositionMapp
   ) where
 
 import           Control.DeepSeq
+import           Control.Lens                ((^.))
 import           Control.Monad
 import           Data.Algorithm.Diff
 import           Data.Bifunctor
@@ -32,6 +32,7 @@ import           Data.List
 import           Data.Row
 import qualified Data.Text                   as T
 import qualified Data.Vector.Unboxed         as V
+import qualified Language.LSP.Protocol.Lens  as L
 import           Language.LSP.Protocol.Types (Position (Position),
                                               Range (Range),
                                               TextDocumentContentChangeEvent (TextDocumentContentChangeEvent),
@@ -131,8 +132,8 @@ addOldDelta delta (PositionMapping pm) =
 -- that was what was done with lsp* 1.6 packages
 applyChange :: PositionDelta -> TextDocumentContentChangeEvent -> PositionDelta
 applyChange PositionDelta{..} (TextDocumentContentChangeEvent (InL x)) = PositionDelta
-    { toDelta = toCurrent (x .! #range) (x .! #text) <=< toDelta
-    , fromDelta = fromDelta <=< fromCurrent (x .! #range) (x .! #text)
+    { toDelta = toCurrent (x ^. L.range) (x ^. L.text) <=< toDelta
+    , fromDelta = fromDelta <=< fromCurrent (x ^. L.range) (x ^. L.text)
     }
 applyChange posMapping _ = posMapping
 
