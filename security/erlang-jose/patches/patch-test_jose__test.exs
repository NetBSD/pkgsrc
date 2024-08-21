$NetBSD: patch-test_jose__test.exs,v 1.1 2024/08/21 15:00:33 adam Exp $

Support OTP json module
https://github.com/potatosalad/erlang-jose/pull/176

--- test/jose_test.exs.orig	2024-08-21 12:51:06.402878295 +0000
+++ test/jose_test.exs
@@ -116,6 +116,18 @@ defmodule JOSETest do
     assert binary == :erlang.element(2, JOSE.JWE.to_binary(jwe))
     assert jwe == JOSE.JWE.from_binary(binary)
     assert jwe == JOSE.JWE.from(jwe)
+
+    if System.otp_release() >= "27" do
+      # OTP json
+      JOSE.json_module(:json)
+      assert :jose_json_otp == JOSE.json_module()
+      assert map == :erlang.element(2, JOSE.JWE.to_map(jwe))
+      assert binary == :erlang.element(2, JOSE.JWE.to_binary(jwe))
+      assert jwe == JOSE.JWE.from_binary(binary)
+      assert jwe == JOSE.JWE.from(jwe)
+    end
+
+    # jsx
     # # jiffy
     # JOSE.json_module(:jiffy)
     # assert :jose_json_jiffy == JOSE.json_module()
