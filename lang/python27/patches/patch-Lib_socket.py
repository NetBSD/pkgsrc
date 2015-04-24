$NetBSD: patch-Lib_socket.py,v 1.1 2015/04/24 03:01:36 rodent Exp $

Fix build with LibreSSL.

--- Lib/socket.py.orig	2014-12-10 15:59:40.000000000 +0000
+++ Lib/socket.py
@@ -67,7 +67,6 @@ else:
     from _ssl import SSLError as sslerror
     from _ssl import \
          RAND_add, \
-         RAND_egd, \
          RAND_status, \
          SSL_ERROR_ZERO_RETURN, \
          SSL_ERROR_WANT_READ, \
@@ -78,6 +77,11 @@ else:
          SSL_ERROR_WANT_CONNECT, \
          SSL_ERROR_EOF, \
          SSL_ERROR_INVALID_ERROR_CODE
+    try:
+        from _ssl import RAND_egd
+    except ImportError:
+        # LibreSSL does not provide RAND_egd
+        pass
 
 import os, sys, warnings
 
