$NetBSD: patch-tests_conftest.py,v 1.1 2026/08/08 15:52:29 wiz Exp $

Upgraded dependencies due to mismatch with system modules
https://github.com/regen100/cmake-language-server/pull/107

--- tests/conftest.py.orig	2025-02-11 02:51:07.305587000 +0000
+++ tests/conftest.py
@@ -1,4 +1,4 @@
-import logging
+import logging 
 import os
 from pathlib import Path
 from subprocess import PIPE, run
@@ -7,7 +7,7 @@ from lsprotocol.types import EXIT, SHUTDOWN
 
 import pytest
 from lsprotocol.types import EXIT, SHUTDOWN
-from pygls.server import LanguageServer
+from pygls.lsp.server import LanguageServer
 
 from cmake_language_server.server import CMakeLanguageServer
 
@@ -51,10 +51,10 @@ def client_server() -> Iterable[Tuple[LanguageServer, 
     yield client, server
 
     # fix bug on python 3.7
-    if hasattr(client.loop, "_signal_handlers"):
-        client.loop._signal_handlers.clear()
+    # if hasattr(client.loop, "_signal_handlers"):
+        # client.loop._signal_handlers.clear()
 
-    client.lsp.send_request(SHUTDOWN)  # type:ignore[no-untyped-call]
-    client.lsp.notify(EXIT)
+    client.protocol.send_request(SHUTDOWN)  # type:ignore[no-untyped-call]
+    client.protocol.notify(EXIT)
     client_thread.join()
     server_thread.join()
