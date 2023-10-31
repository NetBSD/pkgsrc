$NetBSD: patch-src_Darcs_Patch_Index_Monad.hs,v 1.1 2023/10/31 10:58:52 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad

--- src/Darcs/Patch/Index/Monad.hs.orig	2023-10-31 10:51:28.174682881 +0000
+++ src/Darcs/Patch/Index/Monad.hs
@@ -30,6 +30,7 @@ import Darcs.Patch.Index.Types ( PatchMo
 import Darcs.Patch.Info ( makePatchname, PatchInfo )
 import Darcs.Patch.Apply ( Apply(..) )
 import Darcs.Patch.ApplyMonad ( ApplyMonad(..), ApplyMonadTree(..) )
+import Control.Monad
 import Control.Monad.State
 import Control.Arrow
 import Darcs.Util.Path ( AnchoredPath, anchorPath, movedirfilename, isPrefix )
