$NetBSD: patch-src_config_src_config__app.erl,v 1.2 2019/09/06 09:10:48 jperkin Exp $

Set pkgsrc standard paths.

--- src/config/src/config_app.erl.orig	2018-11-13 07:09:52.000000000 +0000
+++ src/config/src/config_app.erl
@@ -48,7 +48,7 @@ command_line() ->
     end.
 
 default() ->
-    Etc = filename:join(code:root_dir(), "etc"),
+    Etc = "@PKG_SYSCONFDIR@",
     Default = [
         filename:join(Etc, "default.ini"),
         filename:join(Etc, "default.d"),
