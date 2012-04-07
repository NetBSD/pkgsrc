$NetBSD: patch-stsci_distutils_hack.py,v 1.1 2012/04/07 11:32:30 joerg Exp $

--- stsci_distutils_hack.py.orig	2010-04-14 11:20:48.000000000 +0000
+++ stsci_distutils_hack.py
@@ -237,8 +237,8 @@ def __get_svn_rev__(path):
     try:
         # with popen3,  stderr goes into a pipe where we ignore it,
         # This means the user does not see errors.
-        cmd = 'svnversion '+path
-        (sin, sout, serr) = os.popen3(cmd)
+        cmd = 'svnversion %s 2>/dev/null' % path
+        sout = os.popen(cmd)
 
         # pick up the first line of output
         m=sout.read().strip()
@@ -261,7 +261,7 @@ def __get_full_info__(path):
     try:
         # with popen3,  stderr goes into a pipe where we ignore it,
         # This means the user does not see errors.
-        (sin, sout, serr) = os.popen3('svn info %s' % path)
+        sout = os.popen('svn info %s 2>/dev/null' % path)
 
         # pick up all the lines of output
         info = [l.strip() for l in sout.readlines()]
