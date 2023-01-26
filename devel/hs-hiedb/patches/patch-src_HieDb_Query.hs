$NetBSD: patch-src_HieDb_Query.hs,v 1.1 2023/01/26 17:46:41 pho Exp $

Fix build with algebraic-graphs-0.7:
https://github.com/wz1000/HieDb/pull/44

--- src/HieDb/Query.hs.orig	2023-01-26 17:43:53.352091323 +0000
+++ src/HieDb/Query.hs
@@ -267,4 +267,4 @@ getReachableUnreachable db symbols = do
   return (Set.toList xs, Set.toList ys)
 
 splitByReachability :: Ord a => AdjacencyMap a -> [a] -> (Set a, Set a)
-splitByReachability m vs = let s = Set.fromList (dfs vs m) in (s, vertexSet m Set.\\ s)
+splitByReachability m vs = let s = Set.fromList (dfs m vs) in (s, vertexSet m Set.\\ s)
