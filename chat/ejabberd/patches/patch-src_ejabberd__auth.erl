$NetBSD: patch-src_ejabberd__auth.erl,v 1.1 2024/08/23 12:59:05 gdt Exp $

Adjust erlang code based on pattern recognition without understanding.

To be filed upstream after pkgsrc is up to date.

--- src/ejabberd_auth.erl.orig	2024-08-22 22:15:04.612183309 +0000
+++ src/ejabberd_auth.erl
@@ -409,7 +409,7 @@ user_exists(User, Server) ->
 	    false
     end.
 
--spec user_exists_in_other_modules(atom(), binary(), binary()) -> boolean() | maybe.
+-spec user_exists_in_other_modules(atom(), binary(), binary()) -> boolean() | maybe_exists.
 user_exists_in_other_modules(Module, User, Server) ->
     user_exists_in_other_modules_loop(
       auth_modules(Server) -- [Module], User, Server).
@@ -423,7 +423,7 @@ user_exists_in_other_modules_loop([AuthM
 	false ->
 	    user_exists_in_other_modules_loop(AuthModules, User, Server);
 	{error, _} ->
-	    maybe
+	    maybe_exists
     end.
 
 -spec which_users_exists(list({binary(), binary()})) -> list({binary(), binary()}).
