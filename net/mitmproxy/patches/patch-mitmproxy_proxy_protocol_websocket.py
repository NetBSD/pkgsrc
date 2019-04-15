$NetBSD: patch-mitmproxy_proxy_protocol_websocket.py,v 1.1 2019/04/15 10:19:55 leot Exp $

Adjust for py-wsproto 0.13.0.

--- mitmproxy/proxy/protocol/websocket.py.orig	2018-07-31 12:01:45.000000000 +0000
+++ mitmproxy/proxy/protocol/websocket.py
@@ -4,8 +4,8 @@ from OpenSSL import SSL
 
 
 import wsproto
-from wsproto import events
-from wsproto.connection import ConnectionType, WSConnection
+from wsproto import events, WSConnection
+from wsproto.connection import ConnectionType
 from wsproto.extensions import PerMessageDeflate
 
 from mitmproxy import exceptions
