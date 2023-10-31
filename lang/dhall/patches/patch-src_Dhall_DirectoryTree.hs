$NetBSD: patch-src_Dhall_DirectoryTree.hs,v 1.1 2023/10/31 08:46:24 pho Exp $

No idea why but System.PosixCompat.User from unix-compat has been removed.

--- src/Dhall/DirectoryTree.hs.orig	2023-10-31 08:26:39.723875281 +0000
+++ src/Dhall/DirectoryTree.hs
@@ -54,8 +54,8 @@ import qualified Prettyprinter          
 import qualified Prettyprinter.Render.String as Pretty
 import qualified System.Directory            as Directory
 import qualified System.FilePath             as FilePath
+import qualified System.Posix.User           as Posix
 import qualified System.PosixCompat.Files    as Posix
-import qualified System.PosixCompat.User     as Posix
 
 {-| Attempt to transform a Dhall record into a directory tree where:
 
