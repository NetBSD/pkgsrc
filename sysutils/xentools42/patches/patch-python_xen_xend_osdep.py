$NetBSD: patch-python_xen_xend_osdep.py,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- python/xen/xend/osdep.py.orig	2011-04-01 12:03:13.000000000 +0200
+++ python/xen/xend/osdep.py	2011-04-01 13:49:45.000000000 +0200
@@ -94,8 +94,12 @@
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
