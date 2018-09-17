$NetBSD: patch-deps_rabbitmq__cli_lib_rabbitmq_cli_core_parser.ex,v 1.1 2018/09/17 18:07:37 fhajny Exp $

Backport elixir 1.7.x support.
https://github.com/rabbitmq/rabbitmq-cli/pull/257

--- deps/rabbitmq_cli/lib/rabbitmq/cli/core/parser.ex.orig	2018-06-14 08:10:14.000000000 +0000
+++ deps/rabbitmq_cli/lib/rabbitmq/cli/core/parser.ex
@@ -142,7 +142,12 @@ defmodule RabbitMQ.CLI.Core.Parser do
     switches = default_switches()
     aliases = default_aliases()
     {options, tail, invalid} =
-      OptionParser.parse_head(input, strict: switches, aliases: aliases)
+      OptionParser.parse_head(
+        input,
+        strict: switches,
+        aliases: aliases,
+        allow_nonexistent_atoms: true,
+      )
     norm_options = normalize_options(options, switches) |> Map.new
     {norm_options, tail, invalid}
   end
