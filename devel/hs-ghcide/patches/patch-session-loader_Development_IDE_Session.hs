$NetBSD: patch-session-loader_Development_IDE_Session.hs,v 1.1 2024/05/04 11:24:53 pho Exp $

Fix build with newer hie-bios. Already fixed in upstream HEAD.

--- session-loader/Development/IDE/Session.hs.orig	2024-05-04 11:11:27.236113902 +0000
+++ session-loader/Development/IDE/Session.hs
@@ -718,7 +718,7 @@ cradleToOptsAndLibDir recorder cradle fi
     --     noneCradleFoundMessage f = T.pack $ "none cradle found for " <> f <> ", ignoring the file"
     -- Start off by getting the session options
     logWith recorder Debug $ LogCradle cradle
-    cradleRes <- HieBios.getCompilerOptions file old_files cradle
+    cradleRes <- HieBios.getCompilerOptions file (LoadWithContext old_files) cradle
     case cradleRes of
         CradleSuccess r -> do
             -- Now get the GHC lib dir
