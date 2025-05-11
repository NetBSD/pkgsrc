$NetBSD: patch-texmf-dist_web2c_texmfcnf.lua,v 1.9 2025/05/11 04:17:39 markd Exp $

Set paths to texmf trees for pkgsrc.

--- texmf-dist/web2c/texmfcnf.lua.orig	2025-02-08 18:30:19.000000000 +0000
+++ texmf-dist/web2c/texmfcnf.lua
@@ -48,11 +48,13 @@ return {
 
          -- TEXMFCACHE      = "$SELFAUTOPARENT/texmf-cache",
 
+            TEXMFCNF        = "@PKG_SYSCONFDIR@",
+
             -- texlive
 
             TEXMFVAR        = "home:" .. hiddentexlivepath .. "/texmf-var",
             TEXMFCONFIG     = "home:" .. hiddentexlivepath .. "/texmf-config",
-            TEXMFSYSVAR     = "selfautoparent:texmf-var",
+            TEXMFSYSVAR     = "@VARBASE@/lib/texmf",
             TEXMFCACHE      = "$TEXMFSYSVAR;$TEXMFVAR",
 
             -- I don't like this texmf under home and texmf-home would make more sense. One never knows
@@ -74,7 +76,7 @@ return {
             -- texlive:
 
             TEXMFDIST       = "selfautoparent:texmf-dist",
-            TEXMFSYSCONFIG  = "selfautoparent:texmf-config",
+            TEXMFSYSCONFIG  = "@PKG_SYSCONFDIR@",
 
             -- The texmf-local path is only used for (maybe) some additional configuration file.
 	    -- Changed texmf-local to use ../ per Bruno Voisin,
