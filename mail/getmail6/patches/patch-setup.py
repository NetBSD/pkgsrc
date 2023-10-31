$NetBSD: patch-setup.py,v 1.1 2023/10/31 01:54:45 sekiya Exp $

Fix mandir per pkgsrc

--- setup.py~	2023-10-31 10:46:37.492574240 +0900
+++ setup.py	2023-10-31 10:46:56.670550748 +0900
@@ -39,7 +39,7 @@
 DOCDIR = os.path.join('share','doc','getmail-%s' % __version__)
 GETMAILDOCDIR = os.path.join(datadir or prefix, DOCDIR)
 
-MANDIR = os.path.join('share','man','man1')
+MANDIR = os.path.join('man','man1')
 GETMAILMANDIR = os.path.join( datadir or prefix, MANDIR)
 
 if '--show-default-install-dirs' in args:
