$NetBSD: patch-test_lib_TestGyp.py,v 1.2 2017/01/11 14:47:51 wiz Exp $

NetBSD's make uses plain quotes.

--- test/lib/TestGyp.py.orig	2017-01-11 14:31:33.000000000 +0000
+++ test/lib/TestGyp.py
@@ -570,7 +570,7 @@ class TestGypMake(TestGypBase):
       message_target = 'all'
     else:
       message_target = target
-    kw['stdout'] = "make: Nothing to be done for `%s'.\n" % message_target
+    kw['stdout'] = "make: Nothing to be done for '%s'.\n" % message_target
     return self.build(gyp_file, target, **kw)
   def run_built_executable(self, name, *args, **kw):
     """
@@ -1002,7 +1002,7 @@ class TestGypXcode(TestGypBase):
                             "PhaseScriptExecution /\\S+/Script-[0-9A-F]+\\.sh\n"
                             "    cd /\\S+\n"
                             "    /bin/sh -c /\\S+/Script-[0-9A-F]+\\.sh\n"
-                            "(make: Nothing to be done for `all'\\.\n)?")
+                            "(make: Nothing to be done for 'all'\\.\n)?")
 
   strip_up_to_date_expressions = [
     # Various actions or rules can run even when the overall build target
