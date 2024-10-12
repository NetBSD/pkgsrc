$NetBSD: patch-python_mozbuild_mozbuild_action_node.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- python/mozbuild/mozbuild/action/node.py.orig	2024-10-11 13:41:58.827020901 +0000
+++ python/mozbuild/mozbuild/action/node.py
@@ -2,7 +2,7 @@
 # License, v. 2.0. If a copy of the MPL was not distributed with this
 # file, You can obtain one at http://mozilla.org/MPL/2.0/.
 
-import pipes
+import shlex
 import subprocess
 import sys
 
@@ -47,7 +47,7 @@ def execute_node_cmd(node_cmd_list):
     """
 
     try:
-        printable_cmd = " ".join(pipes.quote(arg) for arg in node_cmd_list)
+        printable_cmd = " ".join(shlex.quote(arg) for arg in node_cmd_list)
         print('Executing "{}"'.format(printable_cmd), file=sys.stderr)
         sys.stderr.flush()
 
