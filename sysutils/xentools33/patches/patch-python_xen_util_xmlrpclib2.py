$NetBSD: patch-python_xen_util_xmlrpclib2.py,v 1.1.2.2 2012/04/07 20:31:10 spz Exp $

--- python/xen/util/xmlrpclib2.py.orig	2012-04-02 21:20:21.000000000 +0000
+++ python/xen/util/xmlrpclib2.py
@@ -58,6 +58,9 @@ def stringify(value):
 # some bugs in Keep-Alive handling and also enabled it by default
 class XMLRPCRequestHandler(SimpleXMLRPCRequestHandler):
     protocol_version = "HTTP/1.1"
+    # xend crashes in python 2.7 unless disable_nagle_algorithm = False
+    # it isn't used in earlier versions so it is harmless to set it generally
+    disable_nagle_algorithm = False
 
     def __init__(self, hosts_allowed, request, client_address, server):
         self.hosts_allowed = hosts_allowed
