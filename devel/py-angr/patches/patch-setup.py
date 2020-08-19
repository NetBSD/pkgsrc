$NetBSD: patch-setup.py,v 1.1 2020/08/19 16:25:08 riastradh Exp $

Allow unicorn 1.0.1, which is what we have in pkgsrc.

Judging by the commit history, unicorn>=1.0.2 is needed only for
building on Windows.

--- setup.py.orig	2020-07-28 02:00:38.000000000 +0000
+++ setup.py
@@ -129,7 +129,7 @@ if 'bdist_wheel' in sys.argv and '--plat
         # https://www.python.org/dev/peps/pep-0425/
         sys.argv.append(name.replace('.', '_').replace('-', '_'))
 
-_UNICORN = "unicorn>=1.0.2rc4"
+_UNICORN = "unicorn>=1.0.1"
 
 setup(
     name='angr',
