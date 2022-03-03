$NetBSD: patch-Lib_ftplib.py,v 1.1.2.2 2022/03/03 19:33:58 bsiegert Exp $

Fix CVE-2021-4189: ftplib should not use the host from the PASV response
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/40dd05e5d77dbfa81777c9f84b704bc2239bf710/f/00372-CVE-2021-4189.patch

--- Lib/ftplib.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/ftplib.py
@@ -108,6 +108,8 @@ class FTP:
     file = None
     welcome = None
     passiveserver = 1
+    # Disables security if set to True. https://bugs.python.org/issue43285
+    trust_server_pasv_ipv4_address = False
 
     # Initialization method (called by class instantiation).
     # Initialize host to localhost, port to standard ftp port
@@ -310,8 +312,13 @@ class FTP:
         return sock
 
     def makepasv(self):
+        """Internal: Does the PASV or EPSV handshake -> (address, port)"""
         if self.af == socket.AF_INET:
-            host, port = parse227(self.sendcmd('PASV'))
+            untrusted_host, port = parse227(self.sendcmd('PASV'))
+            if self.trust_server_pasv_ipv4_address:
+                host = untrusted_host
+            else:
+                host = self.sock.getpeername()[0]
         else:
             host, port = parse229(self.sendcmd('EPSV'), self.sock.getpeername())
         return host, port
