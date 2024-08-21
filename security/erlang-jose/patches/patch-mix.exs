$NetBSD: patch-mix.exs,v 1.1 2024/08/21 15:00:33 adam Exp $

Disable warnings_as_error because of OTP deprecation warnings
https://github.com/potatosalad/erlang-jose/pull/172

--- mix.exs.orig	2024-08-21 14:45:33.255363161 +0000
+++ mix.exs
@@ -61,9 +61,7 @@ defmodule JOSE.Mixfile do
   end
 
   def erlc_options() do
-    extra_options = []
-
-    [:debug_info | if(Mix.env() == :prod, do: [], else: [:warnings_as_errors]) ++ extra_options]
+    [:debug_info]
   end
 
   defp package() do
