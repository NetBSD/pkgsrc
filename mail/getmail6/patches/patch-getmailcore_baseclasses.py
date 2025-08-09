$NetBSD: patch-getmailcore_baseclasses.py,v 1.1 2025/08/09 20:10:23 wiz Exp $

Use multiprocessing instead of mixing signals and threading condvars for process synchronization
https://github.com/getmail6/getmail6/pull/246

--- getmailcore/baseclasses.py.orig	2025-05-14 19:25:00.000000000 +0000
+++ getmailcore/baseclasses.py
@@ -15,7 +15,7 @@ import codecs
 from collections import namedtuple
 import tempfile
 import errno
-from threading import Condition
+from multiprocessing import Process
 
 from argparse import Namespace
 import subprocess
@@ -399,59 +399,29 @@ class ForkingBase(object):
         log - an object of type getmailcore.logging.Logger()
 
     '''
-    def _SIGCHLD_handler(self, sig, stackframe):
-        def notify():
-            self.__child_exited.acquire()
-            self.__child_exited.notify_all()
-            self.__child_exited.release()
-        self.log.trace('handler called for signal %s' % sig)
-        try:
-            pid, r = os.waitpid(self.child.childpid,0)
-        except Exception as o:
-            self.log.trace('handler called with exception (%s)' % o)
-            notify()
-            return
-        if self.__orig_handler:
-            signal.signal(signal.SIGCHLD, self.__orig_handler)
-        self.__child_pid = pid
-        self.__child_status = r
-        self.log.trace('handler reaped child %s with status %s' % (pid, r))
-        notify()
-
-    def _prepare_child(self):
-        self.log.trace('')
-        self.__child_exited = Condition()
-        self.__child_pid = 0
-        self.__child_status = None
-        self.__orig_handler = None
-        self.__orig_handler = signal.signal(signal.SIGCHLD, self._SIGCHLD_handler)
-
-    def _wait_for_child(self, childpid):
-        self.__child_exited.acquire()
-        if self.__child_exited.wait(60) == False:
-            raise getmailOperationError('waiting child pid %d timed out'
-                                        % childpid)
-        self.__child_exited.release()
-        if self.__child_pid != childpid:
-            #self.log.error('got child pid %d, not %d' % (pid, childpid))
-            raise getmailOperationError(
-                'got child pid %d, not %d'
-                % (self.__child_pid, childpid)
-            )
-        if os.WIFSTOPPED(self.__child_status):
-            raise getmailOperationError(
-                'child pid %d stopped by signal %d'
-                % (self.__child_pid, os.WSTOPSIG(self.__child_status))
-            )
-        if os.WIFSIGNALED(self.__child_status):
+
+    def _wait_for_child(self, child):
+        proc = child.process
+        pid = proc.pid
+        proc.join(timeout=60)
+        # If child is still alive we joined due to timeout.
+        if (proc.is_alive()):
+            proc.terminate()
+        exitcode = proc.exitcode
+
+        if (exitcode is None):
+            raise getmailOperationError('child pid %d failed to exit' % pid)
+        if (exitcode < 0):
+            # Child killed by a signal
+            try:
+                sig = signal.Signals(-exitcode).name
+            except:
+                sig = str(-exitcode)
+
             raise getmailOperationError(
-                'child pid %d killed by signal %d'
-                % (self.__child_pid, os.WTERMSIG(self.__child_status))
-            )
-        if not os.WIFEXITED(self.__child_status):
-            raise getmailOperationError('child pid %d failed to exit'
-                                        % self.__child_pid)
-        exitcode = os.WEXITSTATUS(self.__child_status)
+                'child pid %d killed by signal %s'
+                % (pid, sig))
+
         return exitcode
 
     def _pipemail(self, msg, delivered_to, received, unixfrom, stdout, stderr):
@@ -478,20 +448,17 @@ class ForkingBase(object):
         self.child = child = Namespace()
         child.stdout = TemporaryFile23()
         child.stderr = TemporaryFile23()
-        child.childpid = os.fork()
-        if child.childpid != 0: # here (in the parent)
-            self._prepare_child()
-            self.log.trace('spawned child %d\n' % child.childpid)
-            child.exitcode = self._wait_for_child(child.childpid)
-            child.stderr.seek(0)
-            child.err = child.stderr.read().strip().decode()
-            child.stdout.seek(0)
-            if with_out:
-                child.out = child.stdout.read().strip()
-            return child
-        else: #== 0 in the child
-            # calls child_replace_me to execl external command
-            childfun(child.stdout, child.stderr)
+        child.process = Process(target=childfun, args=(child.stdout, child.stderr))
+        child.process.start()
+        child.childpid = child.process.pid
+        self.log.trace('spawned child %d\n' % child.childpid)
+        child.exitcode = self._wait_for_child(child)
+        child.stderr.seek(0)
+        child.err = child.stderr.read().strip().decode()
+        child.stdout.seek(0)
+        if with_out:
+            child.out = child.stdout.read().strip()
+        return child
 
     def get_msginfo(self, msg):
         msginfo = {}
