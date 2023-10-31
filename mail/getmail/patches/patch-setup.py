$NetBSD: patch-setup.py,v 1.2 2023/10/31 14:56:12 schmonz Exp $

Use standard pkgsrc paths. Avoid conflicting with getmail6.

--- setup.py.orig	2021-10-31 22:19:59.000000000 +0000
+++ setup.py
@@ -39,13 +39,12 @@ GETMAILDOCDIR = os.path.join(
     datadir or prefix,
     'share',
     'doc',
-    'getmail-%s' % __version__
+    'getmail5'
 )
 
 GETMAILMANDIR = os.path.join(
     datadir or prefix,
-    'share',
-    'man',
+    os.environ["PKGMANDIR"],
     'man1'
 )
 
@@ -89,19 +88,18 @@ setup(
         'Topic :: Utilities',
     ],
     packages=[
-        'getmailcore'
+        'getmail5core'
     ],
     scripts=[
-        'getmail',
-        'getmail_fetch',
-        'getmail_maildir',
-        'getmail_mbox',
-        'getmail-gmail-xoauth-tokens',
+        'getmail5',
+        'getmail5_fetch',
+        'getmail5_maildir',
+        'getmail5_mbox',
+        'getmail5-gmail-xoauth-tokens',
     ],
     data_files=[
         (GETMAILDOCDIR, [
             './README',
-            './getmail.spec',
             'docs/BUGS',
             'docs/COPYING',
             'docs/CHANGELOG',
@@ -119,10 +117,10 @@ setup(
             'docs/troubleshooting.txt',
         ]),
         (GETMAILMANDIR, [
-            'docs/getmail.1',
-            'docs/getmail_fetch.1',
-            'docs/getmail_maildir.1',
-            'docs/getmail_mbox.1',
+            'docs/getmail5.1',
+            'docs/getmail5_fetch.1',
+            'docs/getmail5_maildir.1',
+            'docs/getmail5_mbox.1',
         ]),
     ],
 )
