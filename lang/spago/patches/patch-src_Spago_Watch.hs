$NetBSD: patch-src_Spago_Watch.hs,v 1.1 2023/01/30 07:47:32 pho Exp $

Fix build with fsnotify-0.4: debouncing has been removed; there's not even
a configuration for that now.

--- src/Spago/Watch.hs.orig	2023-01-30 07:42:23.819176897 +0000
+++ src/Spago/Watch.hs
@@ -30,7 +30,7 @@ watch
   => Set.Set Glob.Pattern -> ClearScreen -> AllowIgnored -> RIO env ()
   -> RIO env ()
 watch globs shouldClear allowIgnored action = do
-  let config = Watch.defaultConfig { Watch.confDebounce = Watch.NoDebounce }
+  let config = Watch.defaultConfig
   fileWatchConf config shouldClear allowIgnored $ \getGlobs -> do
     getGlobs globs
     action
