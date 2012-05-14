$NetBSD: patch-python_xen_util_xmlrpcclient.py,v 1.1 2012/05/14 15:39:52 manu Exp $

--- ../tools/python/xen/util/xmlrpcclient.py.orig	2012-05-14 17:14:52.000000000 +0200
+++ ../tools/python/xen/util/xmlrpcclient.py	2012-05-14 17:15:44.000000000 +0200
@@ -21,8 +21,9 @@
 import socket
 import string
 import xmlrpclib
 from types import StringTypes
+from sys import hexversion
 
 
 try:
     import SSHTransport
@@ -53,9 +54,12 @@
         self.__handler = handler
         return xmlrpclib.Transport.request(self, host, '/RPC2',
                                            request_body, verbose)
     def make_connection(self, host):
-        return HTTPUnix(self.__handler)
+        if hexversion < 0x02070000:
+            return HTTPUnix(self.__handler)
+        else:
+            return HTTPUnixConnection(self.__handler)
 
 
 # We need our own transport for HTTPS, because xmlrpclib.SafeTransport is
 # broken -- it does not handle ERROR_ZERO_RETURN properly.
