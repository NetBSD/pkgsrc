$NetBSD: patch-Setup.hs,v 1.1 2020/03/30 16:45:35 riastradh Exp $

Convert to modern cabal API.

--- Setup.hs.orig	2010-11-08 01:31:34.000000000 +0000
+++ Setup.hs
@@ -1,3 +1,3 @@
 #!/usr/bin/env runhaskell
 import Distribution.Simple
-main = defaultMainWithHooks defaultUserHooks
+main = defaultMainWithHooks simpleUserHooks
