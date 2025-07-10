$NetBSD: patch-gprproject_____init____.py,v 1.1 2025/07/10 18:52:41 dkazankov Exp $

Fix parameters throughput

--- gprproject/__init__.py.orig	2024-09-24 12:28:32.000000000 +0300
+++ gprproject/__init__.py
@@ -173,7 +173,7 @@
             print(f'{var:<32} := "{value}";')
 
         if not args.configure_only:
-            status = gpr.build([])
+            status = gpr.build(args.gpr_opts)
             if status == 0 and args.install:
                 status = gpr.install([])
             return status
@@ -182,19 +182,19 @@
 
     def clean(self, args):
         gpr = GPRTool.load(self.project_file)
-        return gpr.clean([])
+        return gpr.clean(args.gpr_opts)
 
     def install(self, args):
         gpr = GPRTool.load(self.project_file)
         if args.prefix:
             gpr.prefix = os.path.abspath(args.prefix)
-        return gpr.install([])
+        return gpr.install(args.gpr_opts)
 
     def uninstall(self, args):
         gpr = GPRTool.load(self.project_file)
         if args.prefix:
             gpr.prefix = os.path.abspath(args.prefix)
-        return gpr.uninstall([])
+        return gpr.uninstall(args.gpr_opts)
 
     def add_arguments(self, parser: argparse.ArgumentParser) -> None:
         """Function to be used by end user to add switch to the build command.
