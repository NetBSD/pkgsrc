$NetBSD: patch-Lib_test_test__ipaddress.py,v 1.1 2020/08/03 11:11:33 wiz Exp $

Fix for CVE-2020-14422

https://github.com/python/cpython/commit/b98e7790c77a4378ec4b1c71b84138cb930b69b7

--- Lib/test/test_ipaddress.py.orig	2020-06-27 08:35:53.000000000 +0000
+++ Lib/test/test_ipaddress.py
@@ -2091,6 +2091,17 @@ class IpaddrUnitTest(unittest.TestCase):
                          sixtofouraddr.sixtofour)
         self.assertFalse(bad_addr.sixtofour)
 
+    # issue41004 Hash collisions in IPv4Interface and IPv6Interface
+    def testV4HashIsNotConstant(self):
+        ipv4_address1 = ipaddress.IPv4Interface("1.2.3.4")
+        ipv4_address2 = ipaddress.IPv4Interface("2.3.4.5")
+        self.assertNotEqual(ipv4_address1.__hash__(), ipv4_address2.__hash__())
+
+    # issue41004 Hash collisions in IPv4Interface and IPv6Interface
+    def testV6HashIsNotConstant(self):
+        ipv6_address1 = ipaddress.IPv6Interface("2001:658:22a:cafe:200:0:0:1")
+        ipv6_address2 = ipaddress.IPv6Interface("2001:658:22a:cafe:200:0:0:2")
+        self.assertNotEqual(ipv6_address1.__hash__(), ipv6_address2.__hash__())
 
 if __name__ == '__main__':
     unittest.main()
