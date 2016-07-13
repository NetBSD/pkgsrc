$NetBSD: patch-texmf-dist_web2c_texmfcnf.lua,v 1.1 2016/07/13 11:17:21 markd Exp $

Set paths to texmf trees for pkgsrc.

--- texmf-dist/web2c/texmfcnf.lua.orig	2016-04-06 22:40:36.000000000 +0000
+++ texmf-dist/web2c/texmfcnf.lua
@@ -42,9 +42,11 @@ return {
             --     "selfautoparent:",
             -- }
 
+            TEXMFCNF        = "@PKG_SYSCONFDIR@",
+
             -- only used for FONTCONFIG_PATH & TEXMFCACHE in TeX Live
 
-            TEXMFSYSVAR     = "selfautoparent:texmf-var",
+            TEXMFSYSVAR     = "@VARBASE@/lib/texmf",
             TEXMFVAR        = "home:.texlive2016/texmf-var",
 
             -- We have only one cache path but there can be more. The first writable one
@@ -62,10 +64,10 @@ return {
             -- entry. This makes the tex root relocatable.
 
             TEXMFOS         = "selfautodir:",
-            TEXMFDIST       = "selfautoparent:texmf-dist",
+            TEXMFDIST       = "selfautodir:share/texmf-dist",
 
-            TEXMFLOCAL      = texmflocal,
-            TEXMFSYSCONFIG  = "selfautoparent:texmf-config",
+            TEXMFLOCAL      = "selfautodir:share/texmf-local",
+            TEXMFSYSCONFIG  = "@PKG_SYSCONFDIR@",
             TEXMFFONTS      = "selfautoparent:texmf-fonts",
             TEXMFPROJECT    = "selfautoparent:texmf-project",
 
@@ -75,7 +77,7 @@ return {
             -- We need texmfos for a few rare files but as I have a few more bin trees
             -- a hack is needed. Maybe other users also have texmf-platform-new trees.
 
-            TEXMF           = "{$TEXMFCONFIG,$TEXMFHOME,!!$TEXMFSYSCONFIG,!!$TEXMFSYSVAR,!!$TEXMFPROJECT,!!$TEXMFFONTS,!!$TEXMFLOCAL,!!$TEXMFDIST}",
+            TEXMF           = "{$TEXMFCONFIG,$TEXMFHOME,!!$TEXMFSYSCONFIG,!!$TEXMFSYSVAR,!!$TEXMFLOCAL,!!$TEXMFDIST}",
 
             TEXFONTMAPS     = ".;$TEXMF/fonts/data//;$TEXMF/fonts/map/{pdftex,dvips}//",
             ENCFONTS        = ".;$TEXMF/fonts/data//;$TEXMF/fonts/enc/{dvips,pdftex}//",
@@ -101,7 +103,7 @@ return {
             PYTHONINPUTS    = ".;$TEXMF/scripts/context/python",
             RUBYINPUTS      = ".;$TEXMF/scripts/context/ruby",
             LUAINPUTS       = ".;$TEXINPUTS;$TEXMF/scripts/context/lua//",
-            CLUAINPUTS      = ".;$SELFAUTOLOC/lib/{context,luatex,}/lua//",
+            CLUAINPUTS      = ".;selfautodir:lib/{context,luatex,}/lua//",
 
             -- Not really used by MkIV so they might go away.
 
