$NetBSD: patch-src_IRTS_System.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

These are pkgsrc-specific paths that need to be substituted.

--- src/IRTS/System.hs.orig	2019-07-22 10:47:26.000000000 +0000
+++ src/IRTS/System.hs
@@ -63,24 +63,13 @@ overrideIdrisSubDirWith fp envVar = do
 getCC :: IO String
 getCC = fromMaybe cc <$> lookupEnv "IDRIS_CC"
   where
-#ifdef mingw32_HOST_OS
-    cc = "gcc"
-#else
-    cc = "cc"
-#endif
+    cc = "@CC@"
 
 getEnvFlags :: IO [String]
 getEnvFlags = maybe [] (splitOn " ") <$> lookupEnv "IDRIS_CFLAGS"
 
-
-#if defined(freebsd_HOST_OS) || defined(dragonfly_HOST_OS)\
-    || defined(openbsd_HOST_OS) || defined(netbsd_HOST_OS)
-extraLib = ["-L/usr/local/lib"]
-extraInclude = ["-I/usr/local/include"]
-#else
-extraLib = []
-extraInclude = []
-#endif
+extraLib = ["-L@PREFIX@/lib", "@COMPILER_RPATH_FLAG@@PREFIX@/lib"]
+extraInclude = ["-I@PREFIX@/include"]
 
 #ifdef IDRIS_GMP
 gmpLib = ["-lgmp", "-DIDRIS_GMP"]
