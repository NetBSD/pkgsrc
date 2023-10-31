$NetBSD: patch-src_Darcs_Patch_Annotate.hs,v 1.1 2023/10/31 10:58:52 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad

--- src/Darcs/Patch/Annotate.hs.orig	2023-10-31 10:50:55.484924756 +0000
+++ src/Darcs/Patch/Annotate.hs
@@ -43,7 +43,8 @@ module Darcs.Patch.Annotate
 
 import Darcs.Prelude
 
-import Control.Monad.State ( modify, modify', when, gets, State, execState )
+import Control.Monad (when)
+import Control.Monad.State ( modify, modify', gets, State, execState )
 
 import qualified Data.ByteString as B
 import qualified Data.ByteString.Char8 as BC
