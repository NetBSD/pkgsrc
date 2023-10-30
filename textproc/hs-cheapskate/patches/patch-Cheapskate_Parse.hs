$NetBSD: patch-Cheapskate_Parse.hs,v 1.1 2023/10/30 02:56:46 pho Exp $

Fix build with GHC 9.6. Functions from Control.Monad are no longer
re-exported by Prelude.

--- Cheapskate/Parse.hs.orig	2023-10-30 02:54:30.013924303 +0000
+++ Cheapskate/Parse.hs
@@ -6,6 +6,7 @@ import Cheapskate.ParserCombinators
 import Cheapskate.Util
 import Cheapskate.Inlines
 import Cheapskate.Types
+import Control.Monad
 import Data.Char hiding (Space)
 import qualified Data.Set as Set
 import Prelude hiding (takeWhile)
