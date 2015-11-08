$NetBSD: patch-xmpp_transports.py,v 1.1 2015/11/08 22:02:57 schnoebe Exp $

Play better with python's after 2.6.

Change how we're creating the SSL object/socket.
Change how we're getting information about the SSL/TLS connection.

Changes taken from debian patch for the same purpose.

--- xmpp/transports.py.orig	2009-04-07 08:34:09.000000000 +0000
+++ xmpp/transports.py
@@ -27,7 +27,7 @@ Transports are stackable so you - f.e. T
 Also exception 'error' is defined to allow capture of this module specific exceptions.
 """
 
-import socket,select,base64,dispatcher,sys
+import socket,ssl,select,base64,dispatcher,sys
 from simplexml import ustr
 from client import PlugIn
 from protocol import *
@@ -312,9 +312,9 @@ class TLS(PlugIn):
         """ Immidiatedly switch socket to TLS mode. Used internally."""
         """ Here we should switch pending_data to hint mode."""
         tcpsock=self._owner.Connection
-        tcpsock._sslObj    = socket.ssl(tcpsock._sock, None, None)
-        tcpsock._sslIssuer = tcpsock._sslObj.issuer()
-        tcpsock._sslServer = tcpsock._sslObj.server()
+        tcpsock._sslObj    = ssl.wrap_socket(tcpsock._sock, None, None)
+        tcpsock._sslIssuer = tcpsock._sslObj.getpeercert().get('issuer')
+        tcpsock._sslServer = tcpsock._sslObj.getpeercert().get('server')
         tcpsock._recv = tcpsock._sslObj.read
         tcpsock._send = tcpsock._sslObj.write
 
