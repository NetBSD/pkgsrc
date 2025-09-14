$NetBSD: patch-awscli_botocore_httpsession.py,v 1.1 2025/09/14 16:54:42 wiz Exp $

strict argument causes problems with latest urllib3.

--- awscli/botocore/httpsession.py.orig	2025-09-14 13:24:50.087211672 +0000
+++ awscli/botocore/httpsession.py
@@ -328,7 +328,6 @@ class URLLib3Session:
 
     def _get_pool_manager_kwargs(self, **extra_kwargs):
         pool_manager_kwargs = {
-            'strict': True,
             'timeout': self._timeout,
             'maxsize': self._max_pool_connections,
             'ssl_context': self._get_ssl_context(),
