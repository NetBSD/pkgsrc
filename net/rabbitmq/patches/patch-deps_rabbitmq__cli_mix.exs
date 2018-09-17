$NetBSD: patch-deps_rabbitmq__cli_mix.exs,v 1.1 2018/09/17 18:07:37 fhajny Exp $

Backport elixir 1.7.x support.
https://github.com/rabbitmq/rabbitmq-cli/pull/257

--- deps/rabbitmq_cli/mix.exs.orig	2018-06-14 08:10:14.000000000 +0000
+++ deps/rabbitmq_cli/mix.exs
@@ -20,7 +20,7 @@ defmodule RabbitMQCtl.MixfileBase do
     [
       app: :rabbitmqctl,
       version: "3.7.5",
-      elixir: "~> 1.6.0",
+      elixir: ">= 1.6.6 and < 1.8.0",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
       escript: [main_module: RabbitMQCtl,
