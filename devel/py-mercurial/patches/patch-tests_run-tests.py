$NetBSD: patch-tests_run-tests.py,v 1.1 2018/01/16 09:24:56 wiz Exp $

# HG changeset patch
# User Jun Wu <quark@fb.com>
# Date 1515456471 28800
# Node ID 87676e8ee05692bda0144e29b0478f2cc339aa4d
# Parent  f948c5b3f5c98815befc91b48aaf88e114c0b8aa
test-run-tests: stabilize the test (issue5735)

Previously there is a race condition because things happen in this order:

  1. Check shouldStop
  2. If shouldStop is false, print the diff
  3. Call fail() -> set shouldStop

The check and set should really happen in a same critical section.

This patch adds a lock to address the issue.

Test Plan:
Run `run-tests.py -l test-run-tests.t` 20 times on gcc112 and the race
condition does not reproduce.

Differential Revision: https://phab.mercurial-scm.org/D1830

--- tests/run-tests.py.orig	2017-12-01 19:49:45.000000000 +0000
+++ tests/run-tests.py
@@ -659,6 +659,7 @@ class Test(unittest.TestCase):
 
     def __init__(self, path, outputdir, tmpdir, keeptmpdir=False,
                  debug=False,
+                 first=False,
                  timeout=None,
                  startport=None, extraconfigopts=None,
                  py3kwarnings=False, shell=None, hgcommand=None,
@@ -711,6 +712,7 @@ class Test(unittest.TestCase):
         self._threadtmp = tmpdir
         self._keeptmpdir = keeptmpdir
         self._debug = debug
+        self._first = first
         self._timeout = timeout
         self._slowtimeout = slowtimeout
         self._startport = startport
@@ -896,9 +898,13 @@ class Test(unittest.TestCase):
                 f.close()
 
             # The result object handles diff calculation for us.
-            if self._result.addOutputMismatch(self, ret, out, self._refout):
-                # change was accepted, skip failing
-                return
+            with firstlock:
+                if self._result.addOutputMismatch(self, ret, out, self._refout):
+                    # change was accepted, skip failing
+                    return
+                if self._first:
+                    global firsterror
+                    firsterror = True
 
             if ret:
                 msg = 'output changed and ' + describe(ret)
@@ -1620,6 +1626,8 @@ class TTest(Test):
         return TTest.ESCAPESUB(TTest._escapef, s)
 
 iolock = threading.RLock()
+firstlock = threading.RLock()
+firsterror = False
 
 class TestResult(unittest._TextTestResult):
     """Holds results when executing via unittest."""
@@ -1705,7 +1713,7 @@ class TestResult(unittest._TextTestResul
 
     def addOutputMismatch(self, test, ret, got, expected):
         """Record a mismatch in test output for a particular test."""
-        if self.shouldStop:
+        if self.shouldStop or firsterror:
             # don't print, some other test case already failed and
             # printed, we're just stale and probably failed due to our
             # temp dir getting cleaned up.
@@ -2637,6 +2645,7 @@ class TestRunner(object):
         t = testcls(refpath, self._outputdir, tmpdir,
                     keeptmpdir=self.options.keep_tmpdir,
                     debug=self.options.debug,
+                    first=self.options.first,
                     timeout=self.options.timeout,
                     startport=self._getport(count),
                     extraconfigopts=self.options.extra_config_opt,
