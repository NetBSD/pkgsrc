$NetBSD: patch-setup.py,v 1.2 2021/06/02 23:27:11 khorben Exp $

Allow unicorn 1.0.1, which is what we have in pkgsrc.

Judging by the commit history, unicorn>=1.0.2 is needed only for
building on Windows.

--- setup.py.orig	2021-05-18 20:52:07.000000000 +0000
+++ setup.py
@@ -130,7 +130,7 @@ if 'bdist_wheel' in sys.argv and '--plat
         # https://www.python.org/dev/peps/pep-0425/
         sys.argv.append(name.replace('.', '_').replace('-', '_'))
 
-_UNICORN = "unicorn==1.0.2rc4"
+_UNICORN = "unicorn>=1.0.1"
 
 setup(
     name='angr',
