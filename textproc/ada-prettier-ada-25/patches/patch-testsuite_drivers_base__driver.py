$NetBSD: patch-testsuite_drivers_base__driver.py,v 1.1 2025/10/03 18:14:19 dkazankov Exp $

Fix test programs path

--- testsuite/drivers/base_driver.py.orig	2024-10-07 18:46:25.000000000 +0300
+++ testsuite/drivers/base_driver.py
@@ -36,6 +36,8 @@
         If the Valgrind mode is enabled, wrap the given command line to run it
         under Valgrind.
         """
+        test_programs = os.environ.get('TEST_PROGRAMS', '')
+        args[0] = os.path.join(test_programs, args[0])
         if self.env.valgrind:
             filename = self.working_dir(
                 f"valgrind-report-{len(self.valgrind_log_files)}.txt"
