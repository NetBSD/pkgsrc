$NetBSD: patch-python_xen_xend_osdep.py,v 1.2 2015/08/23 16:17:12 spz Exp $

--- python/xen/xend/osdep.py.orig	2014-09-02 06:22:57.000000000 +0000
+++ python/xen/xend/osdep.py
@@ -98,8 +98,12 @@ def _netbsd_balloon_stat(label):
         return None
     cmd = "/sbin/sysctl " + cmdarg
     sysctloutput = commands.getoutput(cmd)
+    div = 1
+    if label == 'current' and '=' not in sysctloutput:
+        sysctloutput = commands.getoutput( "/sbin/sysctl hw.physmem64")
+        div = 1024
     (name, value) = sysctloutput.split('=')
-    return int(value)
+    return int(value) / div
 
 def _solaris_balloon_stat(label):
     """Returns the value for the named label, or None if an error occurs."""
