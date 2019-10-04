$NetBSD: patch-lib_transport_nirio_lvbitx_process-lvbitx.py,v 1.1 2019/10/04 10:41:44 adam Exp $

Do not modify output path.

--- lib/transport/nirio/lvbitx/process-lvbitx.py.orig	2019-10-03 18:11:53.000000000 +0000
+++ lib/transport/nirio/lvbitx/process-lvbitx.py
@@ -30,7 +30,7 @@ if (len(args) < 1):
 
 lvbitx_filename = args[0]
 input_filename = os.path.relpath(lvbitx_filename)
-autogen_src_path = os.path.relpath(options.output_src_path) if (options.output_src_path is not None) else os.path.dirname(input_filename)
+autogen_src_path = options.output_src_path if options.output_src_path is not None else os.path.dirname(input_filename)
 class_name = os.path.splitext(os.path.basename(input_filename))[0]
 
 if (not os.path.isfile(input_filename)):
