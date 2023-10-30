$NetBSD: patch-src_Idris_Core_Constraints.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/Constraints.hs.orig	2023-10-30 15:02:15.256279527 +0000
+++ src/Idris/Core/Constraints.hs
@@ -11,6 +11,7 @@ module Idris.Core.Constraints ( ucheck )
 import Idris.Core.TT (ConstraintFC(..), Err'(..), TC(..), UConstraint(..),
                       UExp(..))
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.List (partition)
 import qualified Data.Map.Strict as M
