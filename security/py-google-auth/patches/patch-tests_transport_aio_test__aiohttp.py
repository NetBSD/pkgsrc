$NetBSD: patch-tests_transport_aio_test__aiohttp.py,v 1.1 2024/09/22 16:12:48 wiz Exp $

Fix test.
https://github.com/googleapis/google-auth-library-python/issues/1599

--- tests/transport/aio/test_aiohttp.py.orig	2024-09-22 16:01:57.881298857 +0000
+++ tests/transport/aio/test_aiohttp.py
@@ -15,7 +15,7 @@
 import asyncio
 
 from aioresponses import aioresponses  # type: ignore
-from mock import AsyncMock, Mock, patch
+from unittest.mock import AsyncMock, Mock, patch
 import pytest  # type: ignore
 import pytest_asyncio  # type: ignore
 
