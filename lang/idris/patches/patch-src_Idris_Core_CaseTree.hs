$NetBSD: patch-src_Idris_Core_CaseTree.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/Core/CaseTree.hs.orig	2020-01-20 12:56:46.585655007 +0000
+++ src/Idris/Core/CaseTree.hs
@@ -627,7 +627,7 @@ groupCons cs = gc [] cs
         PConst cval -> return $ addConG cval (ps, res) acc
         PSuc n -> return $ addg False CSuc [n] (ps, res) acc
         PReflected fn args -> return $ addg False (CFn fn) args (ps, res) acc
-        pat -> fail $ show pat ++ " is not a constructor or constant (can't happen)"
+        pat -> error $ show pat ++ " is not a constructor or constant (can't happen)"
 
     addg uniq c conargs res []
            = [ConGroup uniq c [(conargs, res)]]
