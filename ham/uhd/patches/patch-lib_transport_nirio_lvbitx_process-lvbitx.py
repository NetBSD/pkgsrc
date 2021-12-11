$NetBSD: patch-lib_transport_nirio_lvbitx_process-lvbitx.py,v 1.2 2021/12/11 17:39:56 tnn Exp $

Do not modify output path.

--- lib/transport/nirio/lvbitx/process-lvbitx.py.orig	2021-09-29 14:25:58.000000000 +0000
+++ lib/transport/nirio/lvbitx/process-lvbitx.py
@@ -30,7 +30,7 @@ if (len(args) < 1):
 
 lvbitx_filename = args[0]
 input_filename = os.path.realpath(lvbitx_filename)
-autogen_src_path = os.path.realpath(options.output_src_path) if (options.output_src_path is not None) else os.path.dirname(input_filename)
+autogen_src_path = options.output_src_path if options.output_src_path is not None else os.path.dirname(input_filename)
 class_name = os.path.splitext(os.path.basename(input_filename))[0]
 
 if (not os.path.isfile(input_filename)):
