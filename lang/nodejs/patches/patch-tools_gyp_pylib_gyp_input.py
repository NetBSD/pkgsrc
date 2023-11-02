$NetBSD: patch-tools_gyp_pylib_gyp_input.py,v 1.1 2023/11/02 13:18:41 adam Exp $

Use packaging instead of deprecated distutils.

--- tools/gyp/pylib/gyp/input.py.orig	2023-11-02 12:06:18.318323105 +0000
+++ tools/gyp/pylib/gyp/input.py
@@ -16,7 +16,7 @@ import subprocess
 import sys
 import threading
 import traceback
-from distutils.version import StrictVersion
+from packaging.version import Version
 from gyp.common import GypError
 from gyp.common import OrderedSet
 
@@ -1190,7 +1190,7 @@ def EvalSingleCondition(cond_expr, true_
         else:
             ast_code = compile(cond_expr_expanded, "<string>", "eval")
             cached_conditions_asts[cond_expr_expanded] = ast_code
-        env = {"__builtins__": {}, "v": StrictVersion}
+        env = {"__builtins__": {}, "v": Version}
         if eval(ast_code, env, variables):
             return true_dict
         return false_dict
