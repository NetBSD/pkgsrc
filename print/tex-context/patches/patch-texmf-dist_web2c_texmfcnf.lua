$NetBSD: patch-texmf-dist_web2c_texmfcnf.lua,v 1.1 2026/02/17 10:49:05 markd Exp $

Set paths to texmf trees for pkgsrc.

--- texmf-dist/web2c/texmfcnf.lua.orig	2026-02-13 20:50:32.000000000 +0000
+++ texmf-dist/web2c/texmfcnf.lua
@@ -124,8 +124,9 @@ return {
             -- System trees
             TEXMFDIST      = distribution_path,
             TEXMFLOCAL     = system_data,
-            TEXMFSYSCONFIG = system_cache .. "/texmf-config",
-            TEXMFSYSVAR    = system_cache .. "/texmf-var",
+            TEXMFSYSCONFIG = "@PKG_SYSCONFDIR@",
+            TEXMFSYSVAR    = "@VARBASE@/lib/texmf",
+            TEXMFCNF       = "@PKG_SYSCONFDIR@",
 
             -- User trees
             TEXMFCONFIG = user_cache .. "/texmf-config",
