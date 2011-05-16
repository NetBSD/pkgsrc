$NetBSD: patch-lib_bup_t_tgit.py,v 1.1.1.1 2011/05/16 13:52:56 wiz Exp $

Fix test case, from upstream git.

--- lib/bup/t/tgit.py.orig	2011-05-12 16:51:44.000000000 +0000
+++ lib/bup/t/tgit.py
@@ -145,17 +145,18 @@ def test_long_index():
 @wvtest
 def test_check_repo_or_die():
     git.check_repo_or_die()
-    WVPASS('check_repo_or_die')  # if we reach this point the call above passed
+    WVPASS('check_repo_or_die') # if we reach this point the call above passed
 
-    mode = os.stat('pybuptest.tmp').st_mode
-    os.chmod('pybuptest.tmp', 0000)
+    os.rename('pybuptest.tmp/objects/pack', 'pybuptest.tmp/objects/pack.tmp')
+    open('pybuptest.tmp/objects/pack', 'w').close()
     try:
         git.check_repo_or_die()
     except SystemExit, e:
         WVPASSEQ(e.code, 14)
     else:
         WVFAIL()
-    os.chmod('pybuptest.tmp', mode)
+    os.unlink('pybuptest.tmp/objects/pack')
+    os.rename('pybuptest.tmp/objects/pack.tmp', 'pybuptest.tmp/objects/pack')
 
     try:
         git.check_repo_or_die('nonexistantbup.tmp')
