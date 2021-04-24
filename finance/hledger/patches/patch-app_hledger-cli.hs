$NetBSD: patch-app_hledger-cli.hs,v 1.1 2021/04/24 11:12:09 pho Exp $

GHC 9 fails to build a Main module whose 'main' is merely imported
from somewhere else. Possibly a compiler bug?

--- app/hledger-cli.hs.orig	2021-04-24 11:06:54.613572938 +0000
+++ app/hledger-cli.hs
@@ -3,4 +3,6 @@
 
 module Main (main)
 where
-import Hledger.Cli.Main (main)
+import qualified Hledger.Cli.Main as M
+
+main = M.main
