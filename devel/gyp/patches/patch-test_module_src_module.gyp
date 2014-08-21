$NetBSD: patch-test_module_src_module.gyp,v 1.1 2014/08/21 14:49:43 he Exp $

Treat NetBSD mostly like Linux.

--- test/module/src/module.gyp.orig	2014-08-12 13:43:00.000000000 +0000
+++ test/module/src/module.gyp
@@ -17,6 +17,10 @@
         'cflags': ['-fPIC'],
         'libraries': ['-ldl'],
       }],
+      ['OS=="netbsd"', {
+        # Support 64-bit shared libs (also works fine for 32-bit).
+        'cflags': ['-fPIC'],
+      }],
     ],
   },
   'targets': [
