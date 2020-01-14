$NetBSD: patch-compiler_main_DynFlags.hs,v 1.1 2020/01/14 08:46:17 pho Exp $

Fix build on FreeBSD:
https://phabricator.haskell.org/D3773

--- compiler/main/DynFlags.hs.orig	2017-01-03 15:59:18.000000000 +0000
+++ compiler/main/DynFlags.hs
@@ -1339,11 +1339,7 @@ wayOptl :: Platform -> Way -> [String]
 wayOptl _ (WayCustom {}) = []
 wayOptl platform WayThreaded =
         case platformOS platform of
-        -- FreeBSD's default threading library is the KSE-based M:N libpthread,
-        -- which GHC has some problems with.  It's currently not clear whether
-        -- the problems are our fault or theirs, but it seems that using the
-        -- alternative 1:1 threading library libthr works around it:
-        OSFreeBSD  -> ["-lthr"]
+        OSFreeBSD  -> ["-pthread"]
         OSOpenBSD  -> ["-pthread"]
         OSNetBSD   -> ["-pthread"]
         _          -> []
