$NetBSD: patch-src_Development_IDE_Plugin_Completions_Logic.hs,v 1.1 2024/05/04 11:24:53 pho Exp $

Upgrade to latest lsp / lsp-types / lsp-test
https://github.com/haskell/haskell-language-server/pull/4166

--- src/Development/IDE/Plugin/Completions/Logic.hs.orig	2024-05-04 11:03:45.624475760 +0000
+++ src/Development/IDE/Plugin/Completions/Logic.hs
@@ -2,7 +2,6 @@
 {-# LANGUAGE DuplicateRecordFields #-}
 {-# LANGUAGE GADTs                 #-}
 {-# LANGUAGE MultiWayIf            #-}
-{-# LANGUAGE OverloadedLabels      #-}
 
 -- Mostly taken from "haskell-ide-engine"
 module Development.IDE.Plugin.Completions.Logic (
@@ -530,7 +529,7 @@ toggleSnippets ClientCapabilities {_text
   removeSnippetsWhen (not $ enableSnippets && supported)
   where
     supported =
-      Just True == (_textDocument >>= _completion >>= view L.completionItem >>= (\x -> x .! #snippetSupport))
+      Just True == (_textDocument >>= _completion >>= view L.completionItem >>= view L.snippetSupport)
 
 toggleAutoExtend :: CompletionsConfig -> CompItem -> CompItem
 toggleAutoExtend CompletionsConfig{enableAutoExtend=False} x = x {additionalTextEdits = Nothing}
