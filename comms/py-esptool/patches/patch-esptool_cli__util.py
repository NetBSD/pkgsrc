$NetBSD: patch-esptool_cli__util.py,v 1.1 2025/07/22 19:13:18 gdt Exp $

Adjust click usage for >= 8.2.0, vs upstream's expecation of old click.

https://github.com/espressif/esptool/pull/1104

--- esptool/cli_util.py.orig	2025-07-19 20:28:53.595125845 +0000
+++ esptool/cli_util.py
@@ -155,7 +155,7 @@ class AddrFilenamePairType(click.Path):
 
     name = "addr-filename-pair"
 
-    def get_metavar(self, param):
+    def get_metavar(self, param, ctx=None):
         return "<address> <filename>"
 
     def convert(
@@ -294,7 +294,7 @@ class OptionEatAll(click.Option):
         self._eat_all_parser = None
         # Set the metavar dynamically based on the type's metavar
         if self.type and hasattr(self.type, "name"):
-            self.metavar = f"[{self.type.get_metavar(None) or self.type.name.upper()}]"
+            self.metavar = f"[{self.type.get_metavar(None, None) or self.type.name.upper()}]"
 
     def add_to_parser(self, parser, ctx):
         def parser_process(value, state):
