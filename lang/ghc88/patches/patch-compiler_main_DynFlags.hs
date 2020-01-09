$NetBSD: patch-compiler_main_DynFlags.hs,v 1.1 2020/01/09 12:32:24 pho Exp $

Fix building bootkits: the stage being >= 2 doesn't imply that GHCI is
enabled. This is a logic error. We build our bootkits with GHCI
disabled.

--- compiler/main/DynFlags.hs.orig	2020-01-08 12:22:53.874596542 +0000
+++ compiler/main/DynFlags.hs
@@ -250,7 +250,7 @@ import qualified EnumSet
 import GHC.Foreign (withCString, peekCString)
 import qualified GHC.LanguageExtensions as LangExt
 
-#if defined(GHCI)
+#if STAGE >= 2
 import Foreign (Ptr) -- needed for 2nd stage
 #endif
 
