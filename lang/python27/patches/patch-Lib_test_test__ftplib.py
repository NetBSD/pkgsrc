$NetBSD: patch-Lib_test_test__ftplib.py,v 1.1.2.2 2022/03/03 19:33:58 bsiegert Exp $

Fix CVE-2021-4189: ftplib should not use the host from the PASV response
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/40dd05e5d77dbfa81777c9f84b704bc2239bf710/f/00372-CVE-2021-4189.patch

--- Lib/test/test_ftplib.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/test/test_ftplib.py
@@ -67,6 +67,10 @@ class DummyFTPHandler(asynchat.async_cha
         self.rest = None
         self.next_retr_data = RETR_DATA
         self.push('220 welcome')
+        # We use this as the string IPv4 address to direct the client
+        # to in response to a PASV command.  To test security behavior.
+        # https://bugs.python.org/issue43285/.
+        self.fake_pasv_server_ip = '252.253.254.255'
 
     def collect_incoming_data(self, data):
         self.in_buffer.append(data)
@@ -109,7 +113,8 @@ class DummyFTPHandler(asynchat.async_cha
         sock.bind((self.socket.getsockname()[0], 0))
         sock.listen(5)
         sock.settimeout(10)
-        ip, port = sock.getsockname()[:2]
+        port = sock.getsockname()[1]
+        ip = self.fake_pasv_server_ip
         ip = ip.replace('.', ',')
         p1, p2 = divmod(port, 256)
         self.push('227 entering passive mode (%s,%d,%d)' %(ip, p1, p2))
@@ -577,6 +582,26 @@ class TestFTPClass(TestCase):
         # IPv4 is in use, just make sure send_epsv has not been used
         self.assertEqual(self.server.handler_instance.last_received_cmd, 'pasv')
 
+    def test_makepasv_issue43285_security_disabled(self):
+        """Test the opt-in to the old vulnerable behavior."""
+        self.client.trust_server_pasv_ipv4_address = True
+        bad_host, port = self.client.makepasv()
+        self.assertEqual(
+                bad_host, self.server.handler_instance.fake_pasv_server_ip)
+        # Opening and closing a connection keeps the dummy server happy
+        # instead of timing out on accept.
+        socket.create_connection((self.client.sock.getpeername()[0], port),
+                                 timeout=TIMEOUT).close()
+
+    def test_makepasv_issue43285_security_enabled_default(self):
+        self.assertFalse(self.client.trust_server_pasv_ipv4_address)
+        trusted_host, port = self.client.makepasv()
+        self.assertNotEqual(
+                trusted_host, self.server.handler_instance.fake_pasv_server_ip)
+        # Opening and closing a connection keeps the dummy server happy
+        # instead of timing out on accept.
+        socket.create_connection((trusted_host, port), timeout=TIMEOUT).close()
+
     def test_line_too_long(self):
         self.assertRaises(ftplib.Error, self.client.sendcmd,
                           'x' * self.client.maxline * 2)
