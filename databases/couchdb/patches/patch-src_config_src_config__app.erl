$NetBSD: patch-src_config_src_config__app.erl,v 1.1 2016/11/16 15:59:29 fhajny Exp $

Set pkgsrc standard paths.

--- src/config/src/config_app.erl.orig	2016-08-24 19:21:47.000000000 +0000
+++ src/config/src/config_app.erl
@@ -48,7 +48,7 @@ command_line() ->
     end.
 
 default() ->
-    Etc = filename:join(code:root_dir(), "etc"),
+    Etc = "@PKG_SYSCONFDIR@",
     Default = [
         filename:join(Etc, "default.ini"),
         filename:join(Etc, "default.d"),
