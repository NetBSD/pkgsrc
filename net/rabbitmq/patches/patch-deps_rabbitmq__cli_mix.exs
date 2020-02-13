$NetBSD: patch-deps_rabbitmq__cli_mix.exs,v 1.3 2020/02/13 18:31:07 adam Exp $

Allow newer elixir.

--- deps/rabbitmq_cli/mix.exs.orig	2020-02-13 12:29:34.000000000 +0000
+++ deps/rabbitmq_cli/mix.exs
@@ -20,7 +20,7 @@ defmodule RabbitMQCtl.MixfileBase do
     [
       app: :rabbitmqctl,
       version: "3.8.0-dev",
-      elixir: ">= 1.7.0 and < 1.10.0",
+      elixir: ">= 1.7.0",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
       escript: [main_module: RabbitMQCtl,
