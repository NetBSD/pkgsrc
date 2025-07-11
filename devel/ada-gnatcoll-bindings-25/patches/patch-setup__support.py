$NetBSD: patch-setup__support.py,v 1.1 2025/07/11 12:46:50 dkazankov Exp $

Fix gprconfig calls

--- setup_support.py.orig	2024-07-11 14:49:55.000000000 +0300
+++ setup_support.py
@@ -135,24 +135,25 @@
             if args.target is None:
                 self.data['target'] = self.run('gcc', '-dumpmachine',
                                                grab=True)
+                self.data['canonical_target'] = self.run(
+                    'gprconfig', '--config=ada',
+                    '--target=%s' % self.data['target'],
+                    '--mi-show-compilers',
+                    grab=r' 1 normalized_target:(\S*)')
             else:
                 self.data['target'] = args.target
+                self.data['canonical_target'] = args.target
 
             self.data['jobs'] = args.jobs
             self.data['integrated'] = args.integrated
-            self.data['canonical_target'] = self.run(
-                'gprconfig', '--config=ada',
-                '--target=%s' % self.data['target'],
-                '--mi-show-compilers',
-                grab=r' 1 normalized_target:(\S*)')
-
-            default_prefix = os.path.dirname(
-                os.path.dirname(
-                    self.run('gprconfig', '--config=ada',
+
+            if args.prefix == 'auto':
+                default_prefix = os.path.dirname(
+                    os.path.dirname(
+                        self.run('gprconfig', '--config=ada',
                              '--target=%s' % self.data['target'],
                              '--mi-show-compilers',
                              grab=r' 1 path:(.*)')))
-            if args.prefix == 'auto':
                 self.data['prefix'] = default_prefix
             else:
                 self.data['prefix'] = args.prefix
