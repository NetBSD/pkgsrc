$NetBSD: patch-Lib_ipaddress.py,v 1.1 2020/08/03 11:11:33 wiz Exp $

Fix for CVE-2020-14422

https://github.com/python/cpython/commit/b98e7790c77a4378ec4b1c71b84138cb930b69b7

--- Lib/ipaddress.py.orig	2020-06-27 08:35:53.000000000 +0000
+++ Lib/ipaddress.py
@@ -1442,7 +1442,7 @@ class IPv4Interface(IPv4Address):
             return False
 
     def __hash__(self):
-        return self._ip ^ self._prefixlen ^ int(self.network.network_address)
+        return hash((self._ip, self._prefixlen, int(self.network.network_address)))
 
     __reduce__ = _IPAddressBase.__reduce__
 
@@ -2088,7 +2088,7 @@ class IPv6Interface(IPv6Address):
             return False
 
     def __hash__(self):
-        return self._ip ^ self._prefixlen ^ int(self.network.network_address)
+        return hash((self._ip, self._prefixlen, int(self.network.network_address)))
 
     __reduce__ = _IPAddressBase.__reduce__
 
