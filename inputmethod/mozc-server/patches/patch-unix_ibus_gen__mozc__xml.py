$NetBSD: patch-unix_ibus_gen__mozc__xml.py,v 1.7 2016/05/16 11:51:49 ryoon Exp $

* Fix for pkgsrc installation.

--- unix/ibus/gen_mozc_xml.py.orig	2016-05-15 08:11:12.000000000 +0000
+++ unix/ibus/gen_mozc_xml.py
@@ -170,7 +170,7 @@ def main():
   (options, unused_args) = parser.parse_args()
 
   setup_arg = []
-  setup_arg.append(os.path.join(options.server_dir, 'mozc_tool'))
+  setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
   setup_arg.append('--mode=config_dialog')
 
   param_dict = {
