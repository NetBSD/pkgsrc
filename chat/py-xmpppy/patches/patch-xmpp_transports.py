$NetBSD: patch-xmpp_transports.py,v 1.5 2024/11/24 00:52:59 gdt Exp $

Adapt to ssl usage in python 3.12 and up.

Taken from:
  https://github.com/xmpppy/xmpppy/pull/70/

This patch asks python to load the system's configured trust anchors.
Validation and hostname matching are in theory enabled by default.
This is a behavior change from upstream, but it is a bugfix.
See
  https://github.com/xmpppy/xmpppy/issues/71


--- xmpp/transports.py.orig	2022-04-10 18:25:44.000000000 +0000
+++ xmpp/transports.py
@@ -383,8 +383,13 @@ class TLS(PlugIn):
     def _startSSL(self):
         """ Immidiatedly switch socket to TLS mode. Used internally."""
         """ Here we should switch pending_data to hint mode."""
+        context=ssl.create_default_context()
+        # Uncomment if you need to work around trust anchor configuration.
+        #context.check_hostname = False
+        #context.verify_mode = ssl.CERT_NONE
+
         tcpsock=self._owner.Connection
-        tcpsock._sslObj    = ssl.wrap_socket(tcpsock._sock, None, None)
+        tcpsock._sslObj    = context.wrap_socket(tcpsock._sock, server_hostname=self._owner.Server)
         tcpsock._sslIssuer = tcpsock._sslObj.getpeercert().get('issuer')
         tcpsock._sslServer = tcpsock._sslObj.getpeercert().get('server')
         tcpsock._recv = tcpsock._sslObj.read
