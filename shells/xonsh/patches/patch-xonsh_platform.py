$NetBSD: patch-xonsh_platform.py,v 1.1 2016/08/21 11:34:57 kamil Exp $

Cherry-pick upstream patch adding NetBSD support
https://github.com/xonsh/xonsh/pull/1601

--- xonsh/platform.py.orig	2016-08-17 00:35:49.000000000 +0000
+++ xonsh/platform.py
@@ -46,6 +46,12 @@ ON_POSIX = LazyBool(lambda: (os.name == 
 ON_FREEBSD = LazyBool(lambda: (sys.platform.startswith('freebsd')),
                       globals(), 'ON_FREEBSD')
 """``True`` if on a FreeBSD operating system, else ``False``."""
+ON_NETBSD = LazyBool(lambda: (sys.platform.startswith('netbsd')),
+                      globals(), 'ON_NETBSD')
+"""``True`` if on a NetBSD operating system, else ``False``."""
+ON_BSD = LazyBool(lambda: ON_FREEBSD or ON_NETBSD,
+                  globals(), 'ON_BSD')
+"""``True`` if on a BSD operating system, else ``False``."""
 
 
 #
