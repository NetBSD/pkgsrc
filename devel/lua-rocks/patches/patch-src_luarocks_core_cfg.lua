$NetBSD: patch-src_luarocks_core_cfg.lua,v 1.1 2020/07/02 12:13:36 nia Exp $

It seems to not like NetBSD unzip(1).

--- src/luarocks/core/cfg.lua.orig	2020-02-07 10:24:14.000000000 +0000
+++ src/luarocks/core/cfg.lua
@@ -253,7 +253,7 @@ local function make_defaults(lua_version
          MKTEMP = "mktemp",
 
          ZIP = "zip",
-         UNZIP = "unzip -n",
+         UNZIP = "@PREFIX@/bin/unzip -n",
          GUNZIP = "gunzip",
          BUNZIP2 = "bunzip2",
          TAR = "tar",
