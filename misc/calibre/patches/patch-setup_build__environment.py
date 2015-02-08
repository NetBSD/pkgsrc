$NetBSD: patch-setup_build__environment.py,v 1.1 2015/02/08 00:37:10 wiz Exp $

Avoid problem on NetBSD:

####### Building extension magick #######
Compiling magick
Traceback (most recent call last):
  File "setup.py", line 99, in <module>
    sys.exit(main())
  File "setup.py", line 85, in main
    command.run_all(opts)
  File "/scratch/wip/calibre/work/calibre-2.15.0/setup/__init__.py", line 181, in run_all
    self.run_cmd(self, opts)
  File "/scratch/wip/calibre/work/calibre-2.15.0/setup/__init__.py", line 178, in run_cmd
    cmd.run(opts)
  File "/scratch/wip/calibre/work/calibre-2.15.0/setup/extensions.py", line 412, in run
    self.build(ext, dest)
  File "/scratch/wip/calibre/work/calibre-2.15.0/setup/extensions.py", line 456, in build
    if not parallel_build(jobs, self.info):
  File "/scratch/wip/calibre/work/calibre-2.15.0/setup/parallel_build.py", line 32, in parallel_build
    p = Pool(cpu_count)
  File "/usr/pkg/lib/python2.7/multiprocessing/dummy/__init__.py", line 151, in Pool
    return ThreadPool(processes, initializer, initargs)
  File "/usr/pkg/lib/python2.7/multiprocessing/pool.py", line 718, in __init__
    Pool.__init__(self, processes, initializer, initargs)
  File "/usr/pkg/lib/python2.7/multiprocessing/pool.py", line 159, in __init__
    self._repopulate_pool()
  File "/usr/pkg/lib/python2.7/multiprocessing/pool.py", line 223, in _repopulate_pool
    w.start()
  File "/usr/pkg/lib/python2.7/multiprocessing/dummy/__init__.py", line 75, in start
    threading.Thread.start(self)
  File "/usr/pkg/lib/python2.7/threading.py", line 745, in start
    _start_new_thread(self.__bootstrap, ())
thread.error: can't start new thread
 *** Error code 1

(The same chunk works fine in the interactive shell, not sure why
it so reliably breaks. -- wiz 20150207)

See also
http://debian.2.n7.nabble.com/Bug-760865-calibre-FTBFS-on-mips-thread-error-can-t-start-new-thread-td3353306.html

--- setup/build_environment.py.orig	2015-02-07 14:26:27.000000000 +0000
+++ setup/build_environment.py
@@ -43,11 +43,7 @@ if iswindows:
     import win32api
     cpu_count = win32api.GetSystemInfo()[5]
 else:
-    from multiprocessing import cpu_count
-    try:
-        cpu_count = cpu_count()
-    except NotImplementedError:
-        cpu_count = 1
+    cpu_count = 1
 
 def run_pkgconfig(name, envvar, default, flag, prefix):
     ans = []
