$NetBSD: patch-src_Darcs_UI_Commands_Log.hs,v 1.1 2023/10/31 10:58:52 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad

--- src/Darcs/UI/Commands/Log.hs.orig	2023-10-31 10:53:52.414049806 +0000
+++ src/Darcs/UI/Commands/Log.hs
@@ -30,6 +30,7 @@ import Data.List.Ordered ( nubSort )
 import Data.Maybe ( fromMaybe, isJust )
 import Control.Arrow ( second )
 import Control.Exception ( catch, IOException )
+import Control.Monad
 import Control.Monad.State.Strict
 
 import Darcs.UI.PrintPatch ( showFriendly )
