$NetBSD: patch-src_plugins_lua_dmarc.lua,v 1.2 2025/11/02 21:17:43 wiz Exp $

os.date() require integer as second argument but get_date() returns
float on NetBSD.  So, convert return value of get_date() to integer.

This fix is provided from Yoshitaka Tokugawa <toku at tokugawa.org>.

--- src/plugins/lua/dmarc.lua.orig	2025-10-05 18:04:57.000000000 +0000
+++ src/plugins/lua/dmarc.lua
@@ -323,7 +323,7 @@ local function dmarc_validate_policy(tas
 
     -- Prepare and send redis report element
     local period = os.date('%Y%m%d',
-      task:get_date({ format = 'connect', gmt = false }))
+      math.floor(task:get_date({ format = 'connect', gmt = false })))
 
     -- Dmarc domain key must include dmarc domain, rua and period
     local dmarc_domain_key = table.concat(
