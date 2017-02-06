$NetBSD: patch-salt_utils_network.py,v 1.5 2017/02/06 12:48:18 sborrill Exp $

Fix sockstat parsing on NetBSD.
https://github.com/saltstack/salt/pull/39189

--- salt/utils/network.py.orig	2017-01-30 18:13:20.000000000 +0000
+++ salt/utils/network.py	2017-02-06 11:38:34.000000000 +0000
@@ -1057,23 +1057,23 @@
     Parses output of shell 'sockstat' (NetBSD)
     to get connections
 
-    $ sudo sockstat -4
+    $ sudo sockstat -4 -n
     USER    COMMAND     PID     FD  PROTO  LOCAL ADDRESS    FOREIGN ADDRESS
-    root    python2.7   1456    29  tcp4   *.4505           *.*
-    root    python2.7   1445    17  tcp4   *.4506           *.*
-    root    python2.7   1294    14  tcp4   127.0.0.1.11813  127.0.0.1.4505
-    root    python2.7   1294    41  tcp4   127.0.0.1.61115  127.0.0.1.4506
+    root    python2.7   1456    29  tcp    *.4505           *.*
+    root    python2.7   1445    17  tcp    *.4506           *.*
+    root    python2.7   1294    14  tcp    127.0.0.1.11813  127.0.0.1.4505
+    root    python2.7   1294    41  tcp    127.0.0.1.61115  127.0.0.1.4506
 
-    $ sudo sockstat -4 -c -p 4506
+    $ sudo sockstat -4 -c -n -p 4506
     USER    COMMAND     PID     FD  PROTO  LOCAL ADDRESS    FOREIGN ADDRESS
-    root    python2.7   1294    41  tcp4   127.0.0.1.61115  127.0.0.1.4506
+    root    python2.7   1294    41  tcp    127.0.0.1.61115  127.0.0.1.4506
     '''
 
     port = int(port)
     remotes = set()
 
     try:
-        cmd = salt.utils.shlex_split('sockstat -4 -c -p {0}'.format(port))
+        cmd = salt.utils.shlex_split('sockstat -4 -c -n -p {0}'.format(port))
         data = subprocess.check_output(cmd)  # pylint: disable=minimum-python-version
     except subprocess.CalledProcessError as ex:
         log.error('Failed "sockstat" with returncode = {0}'.format(ex.returncode))
@@ -1085,7 +1085,7 @@
         chunks = line.split()
         if not chunks:
             continue
-        # ['root', 'python2.7', '1456', '37', 'tcp4',
+        # ['root', 'python2.7', '1456', '37', 'tcp',
         #  '127.0.0.1.4505-', '127.0.0.1.55703']
         # print chunks
         if 'COMMAND' in chunks[1]:
