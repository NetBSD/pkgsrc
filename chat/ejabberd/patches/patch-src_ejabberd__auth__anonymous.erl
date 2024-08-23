$NetBSD: patch-src_ejabberd__auth__anonymous.erl,v 1.1 2024/08/23 12:59:05 gdt Exp $

Adjust erlang code based on pattern recognition without understanding.

To be filed upstream after pkgsrc is up to date.

--- src/ejabberd_auth_anonymous.erl.orig	2024-08-22 22:18:25.679114701 +0000
+++ src/ejabberd_auth_anonymous.erl
@@ -153,7 +153,7 @@ check_password(User, _AuthzId, Server, _
 	 %% If user exists in other module, reject anonnymous authentication
 	 true -> false;
 	 %% If we are not sure whether the user exists in other module, reject anon auth
-	 maybe -> false;
+	 maybe_exists -> false;
 	 false -> login(User, Server)
      end}.
 
