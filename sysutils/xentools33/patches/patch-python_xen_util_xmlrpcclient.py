$NetBSD: patch-python_xen_util_xmlrpcclient.py,v 1.1.2.2 2012/04/07 20:31:10 spz Exp $

--- python/xen/util/xmlrpcclient.py.orig	2012-04-02 21:17:56.000000000 +0000
+++ python/xen/util/xmlrpcclient.py
@@ -22,6 +22,7 @@ import socket
 import string
 import xmlrpclib
 from types import StringTypes
+from sys import hexversion
 
 
 try:
@@ -54,7 +55,12 @@ class UnixTransport(xmlrpclib.Transport)
         return xmlrpclib.Transport.request(self, host, '/RPC2',
                                            request_body, verbose)
     def make_connection(self, host):
-        return HTTPUnix(self.__handler)
+        if hexversion < 0x02070000:
+            # python 2.6 or earlier
+            return HTTPUnix(self.__handler)
+        else:
+            # xmlrpclib.Transport changed in python 2.7
+            return HTTPUnixConnection(self.__handler)
 
 
 # We need our own transport for HTTPS, because xmlrpclib.SafeTransport is
