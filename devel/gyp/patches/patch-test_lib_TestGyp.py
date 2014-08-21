$NetBSD: patch-test_lib_TestGyp.py,v 1.1 2014/08/21 14:49:43 he Exp $

Our gnu make says "Nothing to be done" with just single quotes.

--- test/lib/TestGyp.py.orig	2014-07-14 14:19:50.000000000 +0000
+++ test/lib/TestGyp.py
@@ -640,7 +640,7 @@ class TestGypAndroid(TestGypBase):
     """
     Verifies that a build of the specified target is up to date.
     """
-    kw['stdout'] = ("make: Nothing to be done for `%s'." %
+    kw['stdout'] = ("make: Nothing to be done for '%s'." %
                     self.target_name(target))
 
     # We need to supply a custom matcher, since we don't want to depend on the
@@ -784,7 +784,7 @@ class TestGypMake(TestGypBase):
       message_target = 'all'
     else:
       message_target = target
-    kw['stdout'] = "make: Nothing to be done for `%s'.\n" % message_target
+    kw['stdout'] = "make: Nothing to be done for '%s'.\n" % message_target
     return self.build(gyp_file, target, **kw)
   def run_built_executable(self, name, *args, **kw):
     """
@@ -1198,7 +1198,7 @@ class TestGypXcode(TestGypBase):
                             "PhaseScriptExecution /\\S+/Script-[0-9A-F]+\\.sh\n"
                             "    cd /\\S+\n"
                             "    /bin/sh -c /\\S+/Script-[0-9A-F]+\\.sh\n"
-                            "(make: Nothing to be done for `all'\\.\n)?")
+                            "(make: Nothing to be done for 'all'\\.\n)?")
 
   strip_up_to_date_expressions = [
     # Various actions or rules can run even when the overall build target
