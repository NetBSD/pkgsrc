$NetBSD: patch-app_Command_Docs_Html.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.Writer no longer re-exports functions from Control.Monad.

--- app/Command/Docs/Html.hs.orig	2023-10-31 07:23:39.912549451 +0000
+++ app/Command/Docs/Html.hs
@@ -9,7 +9,7 @@ import Prelude
 
 import Control.Applicative (Alternative(..))
 import Control.Arrow ((&&&))
-import Control.Monad.Writer (guard)
+import Control.Monad (guard)
 import Data.List (sort)
 import Data.Text (Text)
 import Data.Text.Lazy (toStrict)
