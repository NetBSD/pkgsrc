$NetBSD: patch-setup.py,v 1.1 2017/11/28 13:48:07 hauke Exp $

For pkgsrc, default to PREFIX path

--- setup.py.orig	2006-05-12 05:14:54.000000000 +0000
+++ setup.py
@@ -104,16 +104,10 @@ if sys.platform == 'win32':
     print "incDirList = ", incDirList
     libDirList = [os.path.join(os.path.abspath(SRC), "lib") ]
     libList = [ "dnssd" ]
-elif sys.platform == 'linux2':
-    incDirList = []
-    libDirList = []
-    libList = ["dns_sd"]
-elif sys.platform == 'freebsd5' or sys.platform == 'freebsd6':
-    incDirList = [os.path.join(os.path.abspath('/usr'), 'local', 'include')] 
-    libDirList = [os.path.join(os.path.abspath('/usr'), 'local', 'lib')]
+else:
+    incDirList = [os.path.join(os.path.abspath('%PREFIX%'), 'include')] 
+    libDirList = [os.path.join(os.path.abspath('%PREFIX%'), 'lib')]
     libList = ["dns_sd"]
-elif sys.platform == 'darwin':
-    incDirList = libDirList = libList = []
 
 opts = get_config_vars()
 #for k,v in opts.items():
