$NetBSD: patch-cmake__language__server_server.py,v 1.1 2026/08/08 15:52:29 wiz Exp $

Upgraded dependencies due to mismatch with system modules
https://github.com/regen100/cmake-language-server/pull/107

--- cmake_language_server/server.py.orig	2025-02-11 02:51:07.301587000 +0000
+++ cmake_language_server/server.py
@@ -31,12 +31,11 @@ from lsprotocol.types import (
     TextDocumentPositionParams,
     TextEdit,
 )
-from pygls.server import LanguageServer
+from pygls.lsp.server import LanguageServer
 
 from .api import API
 
 logger = logging.getLogger(__name__)
-
 
 class CMakeLanguageServer(LanguageServer):
     _api: Optional[API]
