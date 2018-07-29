$NetBSD: patch-tlslite_tlsconnection.py,v 1.1 2018/07/29 10:04:00 schmonz Exp $

Rename 'async' parameter (Python 3.7 keyword).

--- tlslite/tlsconnection.py.orig	2015-08-12 05:54:36.000000000 +0000
+++ tlslite/tlsconnection.py
@@ -68,7 +68,7 @@ class TLSConnection(TLSRecordLayer):
 
     def handshakeClientAnonymous(self, session=None, settings=None, 
                                 checker=None, serverName="",
-                                async=False):
+                                tlslite_async=False):
         """Perform an anonymous handshake in the role of client.
 
         This function performs an SSL or TLS handshake using an
@@ -102,8 +102,8 @@ class TLSConnection(TLSRecordLayer):
         @type serverName: string
         @param serverName: The ServerNameIndication TLS Extension.
 
-        @type async: bool
-        @param async: If False, this function will block until the
+        @type tlslite_async: bool
+        @param tlslite_async: If False, this function will block until the
         handshake is completed.  If True, this function will return a
         generator.  Successive invocations of the generator will
         return 0 if it is waiting to read from the socket, 1 if it is
@@ -111,7 +111,7 @@ class TLSConnection(TLSRecordLayer):
         the handshake operation is completed.
 
         @rtype: None or an iterable
-        @return: If 'async' is True, a generator object will be
+        @return: If 'tlslite_async' is True, a generator object will be
         returned.
 
         @raise socket.error: If a socket error occurs.
@@ -126,7 +126,7 @@ class TLSConnection(TLSRecordLayer):
                                                 settings=settings,
                                                 checker=checker,
                                                 serverName=serverName)
-        if async:
+        if tlslite_async:
             return handshaker
         for result in handshaker:
             pass
@@ -134,7 +134,7 @@ class TLSConnection(TLSRecordLayer):
     def handshakeClientSRP(self, username, password, session=None,
                            settings=None, checker=None, 
                            reqTack=True, serverName="",
-                           async=False):
+                           tlslite_async=False):
         """Perform an SRP handshake in the role of client.
 
         This function performs a TLS/SRP handshake.  SRP mutually
@@ -179,8 +179,8 @@ class TLSConnection(TLSRecordLayer):
         @type serverName: string
         @param serverName: The ServerNameIndication TLS Extension.
 
-        @type async: bool
-        @param async: If False, this function will block until the
+        @type tlslite_async: bool
+        @param tlslite_async: If False, this function will block until the
         handshake is completed.  If True, this function will return a
         generator.  Successive invocations of the generator will
         return 0 if it is waiting to read from the socket, 1 if it is
@@ -188,7 +188,7 @@ class TLSConnection(TLSRecordLayer):
         the handshake operation is completed.
 
         @rtype: None or an iterable
-        @return: If 'async' is True, a generator object will be
+        @return: If 'tlslite_async' is True, a generator object will be
         returned.
 
         @raise socket.error: If a socket error occurs.
@@ -206,9 +206,9 @@ class TLSConnection(TLSRecordLayer):
         # fashion, returning 1 when it is waiting to able to write, 0 when
         # it is waiting to read.
         #
-        # If 'async' is True, the generator is returned to the caller, 
+        # If 'tlslite_async' is True, the generator is returned to the caller, 
         # otherwise it is executed to completion here.  
-        if async:
+        if tlslite_async:
             return handshaker
         for result in handshaker:
             pass
@@ -216,7 +216,7 @@ class TLSConnection(TLSRecordLayer):
     def handshakeClientCert(self, certChain=None, privateKey=None,
                             session=None, settings=None, checker=None,
                             nextProtos=None, reqTack=True, serverName="",
-                            async=False):
+                            tlslite_async=False):
         """Perform a certificate-based handshake in the role of client.
 
         This function performs an SSL or TLS handshake.  The server
@@ -273,8 +273,8 @@ class TLSConnection(TLSRecordLayer):
         @type serverName: string
         @param serverName: The ServerNameIndication TLS Extension.
 
-        @type async: bool
-        @param async: If False, this function will block until the
+        @type tlslite_async: bool
+        @param tlslite_async: If False, this function will block until the
         handshake is completed.  If True, this function will return a
         generator.  Successive invocations of the generator will
         return 0 if it is waiting to read from the socket, 1 if it is
@@ -282,7 +282,7 @@ class TLSConnection(TLSRecordLayer):
         the handshake operation is completed.
 
         @rtype: None or an iterable
-        @return: If 'async' is True, a generator object will be
+        @return: If 'tlslite_async' is True, a generator object will be
         returned.
 
         @raise socket.error: If a socket error occurs.
@@ -301,9 +301,9 @@ class TLSConnection(TLSRecordLayer):
         # fashion, returning 1 when it is waiting to able to write, 0 when
         # it is waiting to read.
         #
-        # If 'async' is True, the generator is returned to the caller, 
+        # If 'tlslite_async' is True, the generator is returned to the caller, 
         # otherwise it is executed to completion here.                        
-        if async:
+        if tlslite_async:
             return handshaker
         for result in handshaker:
             pass
