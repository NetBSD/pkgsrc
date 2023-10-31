$NetBSD: patch-setup.py,v 1.2 2023/10/31 14:55:36 schmonz Exp $

Use standard pkgsrc paths. Avoid conflicting with getmail.

--- setup.py.orig	2023-08-22 15:38:27.000000000 +0000
+++ setup.py
@@ -36,10 +36,10 @@ for (pos, arg) in enumerate(args):
         # hack hack hack hack hack hack hack
         datadir = args[pos + 1]
 
-DOCDIR = os.path.join('share','doc','getmail-%s' % __version__)
+DOCDIR = os.path.join('share','doc','getmail6')
 GETMAILDOCDIR = os.path.join(datadir or prefix, DOCDIR)
 
-MANDIR = os.path.join('share','man','man1')
+MANDIR = os.path.join(os.environ["PKGMANDIR"],'man1')
 GETMAILMANDIR = os.path.join( datadir or prefix, MANDIR)
 
 if '--show-default-install-dirs' in args:
@@ -79,15 +79,15 @@ setup(
         'Topic :: Utilities',
     ],
     packages=[
-        'getmailcore'
+        'getmail6core'
     ],
     scripts=[
-        'getmail',
-        'getmails',
-        'getmail_fetch',
-        'getmail_maildir',
-        'getmail_mbox',
-        'getmail-gmail-xoauth-tokens',
+        'getmail6',
+        'getmail6s',
+        'getmail6_fetch',
+        'getmail6_maildir',
+        'getmail6_mbox',
+        'getmail6-gmail-xoauth-tokens',
     ],
     data_files=[
         (DOCDIR, [
@@ -108,11 +108,11 @@ setup(
             'docs/troubleshooting.txt',
         ]),
         (MANDIR, [
-            'docs/getmails.1',
-            'docs/getmail.1',
-            'docs/getmail_fetch.1',
-            'docs/getmail_maildir.1',
-            'docs/getmail_mbox.1',
+            'docs/getmail6s.1',
+            'docs/getmail6.1',
+            'docs/getmail6_fetch.1',
+            'docs/getmail6_maildir.1',
+            'docs/getmail6_mbox.1',
         ]),
     ],
 )
