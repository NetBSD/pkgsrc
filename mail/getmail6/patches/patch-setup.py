$NetBSD: patch-setup.py,v 1.3 2025/08/09 20:10:23 wiz Exp $

Use standard pkgsrc paths.

--- setup.py.orig	2025-05-14 19:25:00.000000000 +0000
+++ setup.py
@@ -39,7 +39,7 @@ for (pos, arg) in enumerate(args):
 DOCDIR = os.path.join('share','doc','getmail')
 GETMAILDOCDIR = os.path.join(datadir or prefix, DOCDIR)
 
-MANDIR = os.path.join('share','man','man1')
+MANDIR = os.path.join(os.environ["PKGMANDIR"],'man1')
 GETMAILMANDIR = os.path.join( datadir or prefix, MANDIR)
 
 if '--show-default-install-dirs' in args:
