$NetBSD: patch-python_xen_util_xmlrpclib2.py,v 1.1 2012/05/14 15:39:52 manu Exp $

--- ../tools/python/xen/util/xmlrpclib2.py.orig	2012-05-14 17:15:51.000000000 +0200
+++ ../tools/python/xen/util/xmlrpclib2.py	2012-05-14 17:16:18.000000000 +0200
@@ -60,8 +60,9 @@
     protocol_version = "HTTP/1.1"
 
     def __init__(self, hosts_allowed, request, client_address, server):
         self.hosts_allowed = hosts_allowed
+        self.disable_nagle_algorithm = False
         SimpleXMLRPCRequestHandler.__init__(self, request, client_address,
                                             server)
 
     # this is inspired by SimpleXMLRPCRequestHandler's do_POST but differs
