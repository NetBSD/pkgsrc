$NetBSD: patch-third__party_libwebrtc_build_chromeos_test__runner.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- third_party/libwebrtc/build/chromeos/test_runner.py.orig	2024-10-11 13:42:59.456381299 +0000
+++ third_party/libwebrtc/build/chromeos/test_runner.py
@@ -9,7 +9,7 @@ import collections
 import json
 import logging
 import os
-import pipes
+import shlex
 import re
 import shutil
 import signal
@@ -342,7 +342,7 @@ class TastTest(RemoteTest):
         # aren't compatible.
         local_test_runner_cmd.append('-extrauseflags=tast_vm')
       if self._attr_expr:
-        local_test_runner_cmd.append(pipes.quote(self._attr_expr))
+        local_test_runner_cmd.append(shlex.quote(self._attr_expr))
       else:
         local_test_runner_cmd.extend(self._tests)
       device_test_script_contents.append(' '.join(local_test_runner_cmd))
@@ -380,7 +380,7 @@ class TastTest(RemoteTest):
         self._attr_expr = '(' + ' || '.join(names) + ')'
 
       if self._attr_expr:
-        # Don't use pipes.quote() here. Something funky happens with the arg
+        # Don't use shlex.quote() here. Something funky happens with the arg
         # as it gets passed down from cros_run_test to tast. (Tast picks up the
         # escaping single quotes and complains that the attribute expression
         # "must be within parentheses".)
