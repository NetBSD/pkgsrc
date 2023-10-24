$NetBSD: patch-src_Control_PatternArrows.hs,v 1.1 2023/10/24 11:32:54 pho Exp $

Fix build with GHC 9.6: The "fix" function appears to be no longer exported
by Prelude.

--- src/Control/PatternArrows.hs.orig	2023-10-24 11:29:41.127932863 +0000
+++ src/Control/PatternArrows.hs
@@ -19,6 +19,7 @@ module Control.PatternArrows where
 
 import Data.Char
 import Control.Monad.State
+import Control.Monad.Fix (fix)
 import qualified Control.Category as C
 import Control.Category ((>>>))
 import qualified Control.Arrow as A
