$NetBSD: patch-deps_rabbitmq__cli_mix.exs,v 1.6 2024/01/06 18:33:23 adam Exp $

Allow Elixir 1.16.

--- deps/rabbitmq_cli/mix.exs.orig	2024-01-06 18:18:30.421394433 +0000
+++ deps/rabbitmq_cli/mix.exs
@@ -11,7 +11,7 @@ defmodule RabbitMQCtl.MixfileBase do
     [
       app: :rabbitmqctl,
       version: "3.12.1",
-      elixir: ">= 1.13.4 and < 1.16.0",
+      elixir: ">= 1.13.4 and < 1.17.0",
       build_embedded: Mix.env() == :prod,
       start_permanent: Mix.env() == :prod,
       escript: [
