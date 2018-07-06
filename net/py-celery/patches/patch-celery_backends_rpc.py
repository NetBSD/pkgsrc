$NetBSD: patch-celery_backends_rpc.py,v 1.1 2018/07/06 07:51:21 adam Exp $

Fix for Python 3.7 (async is a reserved keyword).
https://github.com/celery/celery/pull/4879/files

--- celery/backends/rpc.py.orig	2018-05-21 09:48:16.000000000 +0000
+++ celery/backends/rpc.py
@@ -16,8 +16,7 @@ from celery import states
 from celery._state import current_task, task_join_will_block
 from celery.five import items, range
 
-from . import base
-from .async import AsyncBackendMixin, BaseResultConsumer
+from . import asynchronous, base
 
 __all__ = ('BacklogLimitExceeded', 'RPCBackend')
 
@@ -39,7 +38,7 @@ def _on_after_fork_cleanup_backend(backe
     backend._after_fork()
 
 
-class ResultConsumer(BaseResultConsumer):
+class ResultConsumer(asynchronous.BaseResultConsumer):
     Consumer = kombu.Consumer
 
     _connection = None
@@ -89,7 +88,7 @@ class ResultConsumer(BaseResultConsumer)
             self._consumer.cancel_by_queue(self._create_binding(task_id).name)
 
 
-class RPCBackend(base.Backend, AsyncBackendMixin):
+class RPCBackend(base.Backend, asynchronous.AsyncBackendMixin):
     """Base class for the RPC result backend."""
 
     Exchange = kombu.Exchange
