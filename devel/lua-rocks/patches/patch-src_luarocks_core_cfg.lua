$NetBSD: patch-src_luarocks_core_cfg.lua,v 1.2 2026/01/05 22:10:35 alnsn Exp $

It seems to not like NetBSD unzip(1).

--- src/luarocks/core/cfg.lua.orig	2025-12-28 23:01:55.000000000 +0000
+++ src/luarocks/core/cfg.lua
@@ -251,7 +251,7 @@ local function make_defaults(lua_version
          MKTEMP = "mktemp",
 
          ZIP = "zip",
-         UNZIP = "unzip -n",
+         UNZIP = "@PREFIX@/bin/unzip -n",
          GUNZIP = "gunzip",
          BUNZIP2 = "bunzip2",
          TAR = "tar",
