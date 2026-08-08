$NetBSD: patch-tests_test__server.py,v 1.1 2026/08/08 15:52:29 wiz Exp $

Upgraded dependencies due to mismatch with system modules
https://github.com/regen100/cmake-language-server/pull/107

--- tests/test_server.py.orig	2025-02-11 02:51:07.305587000 +0000
+++ tests/test_server.py
@@ -27,7 +27,7 @@ from lsprotocol.types import (
     TextDocumentIdentifier,
     TextDocumentItem,
 )
-from pygls.server import LanguageServer
+from pygls.lsp.server import LanguageServer
 
 from cmake_language_server.server import CMakeLanguageServer
 
@@ -38,7 +38,7 @@ def _init(client: LanguageServer, root: Path) -> None:
     retry = 3
     while retry > 0:
         try:
-            client.lsp.send_request(  # type:ignore[no-untyped-call]
+            client.protocol.send_request(  # type:ignore[no-untyped-call]
                 INITIALIZE,
                 InitializeParams(
                     process_id=1234,
@@ -56,7 +56,7 @@ def _open(client: LanguageServer, path: Path, text: Op
     if text is None:
         text = path.read_text()
 
-    client.lsp.notify(
+    client.protocol.notify(
         TEXT_DOCUMENT_DID_OPEN,
         DidOpenTextDocumentParams(
             text_document=TextDocumentItem(
@@ -81,7 +81,7 @@ def _test_completion(
         position=Position(line=0, character=len(content)),
         context=context,
     )
-    ret = client.lsp.send_request(  # type:ignore[no-untyped-call]
+    ret = client.protocol.send_request(  # type:ignore[no-untyped-call]
         TEXT_DOCUMENT_COMPLETION, params
     ).result(timeout=CALL_TIMEOUT)
     assert isinstance(ret, CompletionList)
@@ -107,7 +107,7 @@ def test_workspace_did_change_configuration(
 
     old_api = server._api
 
-    client.lsp.notify(
+    client.protocol.notify(
         WORKSPACE_DID_CHANGE_CONFIGURATION,
         DidChangeConfigurationParams(
             settings={"initialization_options": {"buildDirectory": "c_build"}}
@@ -169,7 +169,7 @@ def test_formatting(
     _init(client, datadir)
     path = datadir / "CMakeLists.txt"
     _open(client, path, "a ( b c ) ")
-    response = client.lsp.send_request(  # type:ignore[no-untyped-call]
+    response = client.protocol.send_request(  # type:ignore[no-untyped-call]
         TEXT_DOCUMENT_FORMATTING,
         DocumentFormattingParams(
             text_document=TextDocumentIdentifier(uri=path.as_uri()),
@@ -186,7 +186,7 @@ def test_hover(
     _init(client, datadir)
     path = datadir / "CMakeLists.txt"
     _open(client, path, "project()")
-    response = client.lsp.send_request(  # type:ignore[no-untyped-call]
+    response = client.protocol.send_request(  # type:ignore[no-untyped-call]
         TEXT_DOCUMENT_HOVER,
         HoverParams(
             text_document=TextDocumentIdentifier(uri=path.as_uri()),
