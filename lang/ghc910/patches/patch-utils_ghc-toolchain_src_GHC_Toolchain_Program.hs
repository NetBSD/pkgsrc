$NetBSD: patch-utils_ghc-toolchain_src_GHC_Toolchain_Program.hs,v 1.1 2025/02/03 16:09:09 pho Exp $

Do not resolve command names to absolute paths. Usually it's the right
thing but in pkgsrc it causes problems because, say, --ld=ld gets
transformed to ${WRAPPER_DIR}/bin/ld and baked into
${PREFIX}/lib/${PKGNAME_NOREV}/lib/settings.

Definitely not eligible for upstreaming.

--- utils/ghc-toolchain/src/GHC/Toolchain/Program.hs.orig	2025-02-03 15:03:27.810854587 +0000
+++ utils/ghc-toolchain/src/GHC/Toolchain/Program.hs
@@ -160,7 +160,7 @@ findProgram description userSpec candida
           r <- liftIO $ findExecutable name
           case r of
             Nothing -> throwE $ name ++ " not found in search path"
-            Just x -> return x
+            Just x -> return name
 
 -------------------- Compiling utilities --------------------
 
