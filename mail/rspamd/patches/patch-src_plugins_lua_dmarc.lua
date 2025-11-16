$NetBSD: patch-src_plugins_lua_dmarc.lua,v 1.3 2025/11/16 21:39:50 wiz Exp $

os.date() require integer as second argument but get_date() returns
float on NetBSD.  So, convert return value of get_date() to integer.

This fix is provided from Yoshitaka Tokugawa <toku at tokugawa.org>.

--- src/plugins/lua/dmarc.lua.orig	2025-11-16 21:33:51.465412541 +0000
+++ src/plugins/lua/dmarc.lua
@@ -296,7 +296,7 @@ local function dmarc_validate_policy(tas
 
       -- Prepare and send redis report element
       local period = os.date('%Y%m%d',
-        task:get_date({ format = 'connect', gmt = false }))
+        math.floor(task:get_date({ format = 'connect', gmt = false })))
 
       -- Dmarc domain key must include dmarc domain, rua and period
       local dmarc_domain_key = table.concat(
