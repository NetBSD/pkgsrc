$NetBSD: patch-app_Command_Docs.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.Writer no longer re-exports functions from Control.Monad.

--- app/Command/Docs.hs.orig	2023-10-31 07:24:25.835974146 +0000
+++ app/Command/Docs.hs
@@ -6,7 +6,7 @@ import Prelude
 import Command.Docs.Html (asHtml, writeHtmlModules)
 import Command.Docs.Markdown (asMarkdown, writeMarkdownModules)
 import Control.Applicative (Alternative(..), optional)
-import Control.Monad.Writer (when)
+import Control.Monad (when)
 import Control.Monad.Trans.Except (runExceptT)
 import Data.Maybe (fromMaybe)
 import Data.Text qualified as T
