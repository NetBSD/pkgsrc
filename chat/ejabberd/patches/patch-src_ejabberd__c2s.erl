$NetBSD: patch-src_ejabberd__c2s.erl,v 1.1 2014/11/13 09:45:47 fhajny Exp $

Backport upstream commit to fix CVE-2014-8760
--- src/ejabberd_c2s.erl.orig	2014-07-22 15:42:49.000000000 +0000
+++ src/ejabberd_c2s.erl
@@ -718,7 +718,7 @@ wait_for_feature_request({xmlstreameleme
 	(StateData#state.sockmod):get_sockmod(StateData#state.socket),
     case {xml:get_attr_s(<<"xmlns">>, Attrs), Name} of
       {?NS_SASL, <<"auth">>}
-	  when not ((SockMod == gen_tcp) and TLSRequired) ->
+	  when TLSEnabled or not TLSRequired ->
 	  Mech = xml:get_attr_s(<<"mechanism">>, Attrs),
 	  ClientIn = jlib:decode_base64(xml:get_cdata(Els)),
 	  case cyrsasl:server_start(StateData#state.sasl_state,
@@ -832,7 +832,7 @@ wait_for_feature_request({xmlstreameleme
 		end
 	  end;
       _ ->
-	  if (SockMod == gen_tcp) and TLSRequired ->
+	  if TLSRequired and not TLSEnabled ->
 		 Lang = StateData#state.lang,
 		 send_element(StateData,
 			      ?POLICY_VIOLATION_ERR(Lang,
