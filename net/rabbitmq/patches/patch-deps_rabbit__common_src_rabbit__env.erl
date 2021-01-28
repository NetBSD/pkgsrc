$NetBSD: patch-deps_rabbit__common_src_rabbit__env.erl,v 1.1 2021/01/28 13:18:15 adam Exp $

Use PkgSrc prefix.

--- deps/rabbit_common/src/rabbit_env.erl.orig	2021-01-28 09:54:36.000000000 +0000
+++ deps/rabbit_common/src/rabbit_env.erl
@@ -1187,7 +1187,7 @@ erlang_dist_tcp_port(#{amqp_tcp_port := 
 sys_prefix(#{os_type := {unix, _}} = Context) ->
     case get_env_var("SYS_PREFIX") of
         false ->
-            update_context(Context, sys_prefix, "", default);
+            update_context(Context, sys_prefix, "@PREFIX@", default);
         Value ->
             Dir = normalize_path(Value),
             update_context(Context, sys_prefix, Dir, environment)
