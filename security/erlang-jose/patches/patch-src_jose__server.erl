$NetBSD: patch-src_jose__server.erl,v 1.1 2024/08/21 15:00:33 adam Exp $

Support OTP json module
https://github.com/potatosalad/erlang-jose/pull/176

--- src/jose_server.erl.orig	2024-04-17 17:02:51.000000000 +0000
+++ src/jose_server.erl
@@ -458,9 +458,9 @@ check_json(_Fallback, Entries) ->
 				undefined ->
 					case code:ensure_loaded(elixir) of
 						{module, elixir} ->
-							check_json_modules([ojson, 'Elixir.Jason', 'Elixir.Poison', jiffy, jsone, jsx, thoas]);
+							check_json_modules([json, ojson, 'Elixir.Jason', 'Elixir.Poison', jiffy, jsone, jsx, thoas]);
 						_ ->
-							check_json_modules([ojson, jiffy, jsone, jsx, thoas])
+							check_json_modules([json, ojson, jiffy, jsone, jsx, thoas])
 					end;
 				M when is_atom(M) ->
 					check_json_module(M)
@@ -469,6 +469,8 @@ check_json(_Fallback, Entries) ->
 	[{json_module, JSONModule} | Entries].
 
 %% @private
+check_json_module(json) ->
+	jose_json_otp;
 check_json_module(jiffy) ->
 	jose_json_jiffy;
 check_json_module(jsx) ->
