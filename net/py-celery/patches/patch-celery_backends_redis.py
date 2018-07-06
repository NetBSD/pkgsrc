$NetBSD: patch-celery_backends_redis.py,v 1.1 2018/07/06 07:51:21 adam Exp $

Fix for Python 3.7 (async is a reserved keyword).
https://github.com/celery/celery/pull/4879/files

--- celery/backends/redis.py.orig	2018-06-10 13:53:06.000000000 +0000
+++ celery/backends/redis.py
@@ -19,7 +19,7 @@ from celery.utils.functional import dict
 from celery.utils.log import get_logger
 from celery.utils.time import humanize_seconds
 
-from . import async, base
+from . import asynchronous, base
 
 try:
     from urllib.parse import unquote
@@ -74,7 +74,7 @@ E_LOST = 'Connection to Redis lost: Retr
 logger = get_logger(__name__)
 
 
-class ResultConsumer(async.BaseResultConsumer):
+class ResultConsumer(asynchronous.BaseResultConsumer):
     _pubsub = None
 
     def __init__(self, *args, **kwargs):
@@ -138,7 +138,7 @@ class ResultConsumer(async.BaseResultCon
             self._pubsub.unsubscribe(key)
 
 
-class RedisBackend(base.BaseKeyValueStoreBackend, async.AsyncBackendMixin):
+class RedisBackend(base.BaseKeyValueStoreBackend, asynchronous.AsyncBackendMixin):
     """Redis task result store."""
 
     ResultConsumer = ResultConsumer
