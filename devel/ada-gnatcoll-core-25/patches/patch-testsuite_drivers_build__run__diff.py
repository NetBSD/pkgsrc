$NetBSD: patch-testsuite_drivers_build__run__diff.py,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

There is no shell other than bash ;-)

--- testsuite/drivers/build_run_diff.py.orig	2024-09-24 12:28:32.000000000 +0300
+++ testsuite/drivers/build_run_diff.py
@@ -82,7 +82,7 @@
         else:
             p = run_test_program(
                 self,
-                ["bash", self.working_dir("test.sh")],
+                ["/bin/sh", self.working_dir("test.sh")],
                 self.slot,
                 timeout=self.default_process_timeout,
             )
