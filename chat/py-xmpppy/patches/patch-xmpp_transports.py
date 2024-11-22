$NetBSD: patch-xmpp_transports.py,v 1.3 2024/11/22 13:45:36 gdt Exp $

Adapt to ssl usage in python 3.12 and up.

Taken from:
  https://github.com/xmpppy/xmpppy/pull/70/

NB: This patch disables validation entirely, matching the previous
behavior.  This is a bug and it is \todo to to enable validation.
  https://github.com/xmpppy/xmpppy/issues/71

Comment for after validation is enabled:

This patch enables check_hostname, and in theory that should result in
certificate validation using the system's configured trust anchors,
and also hostname matching.  Perhaps this is a behavior change from
before, but if so it is a bugfix.

--- xmpp/transports.py.orig	2022-04-10 18:25:44.000000000 +0000
+++ xmpp/transports.py
@@ -383,8 +383,13 @@ class TLS(PlugIn):
     def _startSSL(self):
         """ Immidiatedly switch socket to TLS mode. Used internally."""
         """ Here we should switch pending_data to hint mode."""
+        context=ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
+        # \todo Fix this after understanding validation a bit better
+        context.check_hostname = False
+        context.verify_mode = ssl.CERT_NONE
+
         tcpsock=self._owner.Connection
-        tcpsock._sslObj    = ssl.wrap_socket(tcpsock._sock, None, None)
+        tcpsock._sslObj    = context.wrap_socket(tcpsock._sock, server_hostname=self._owner.Server)
         tcpsock._sslIssuer = tcpsock._sslObj.getpeercert().get('issuer')
         tcpsock._sslServer = tcpsock._sslObj.getpeercert().get('server')
         tcpsock._recv = tcpsock._sslObj.read
