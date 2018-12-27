$NetBSD: patch-dropbox_datastore.py,v 1.1 2018/12/27 15:04:42 joerg Exp $

--- dropbox/datastore.py.orig	2018-12-25 21:56:18.018562969 +0000
+++ dropbox/datastore.py
@@ -266,7 +266,7 @@ class _DatastoreOperations(object):
         resp = self._client.rest_client.POST(url, params, headers)
         return self._check_conflict(resp)
 
-    def await(self, token=None, cursors=None):
+    def send_await(self, token=None, cursors=None):
         params = {}
         if token:
             params['list_datastores'] = json.dumps({'token': token})
@@ -407,7 +407,7 @@ class DatastoreManager(object):
         resp = self._dsops.list_datastores()
         return [_make_dsinfo(item) for item in resp['datastores']]
 
-    def await(self, token=None, datastores=None):
+    def send_await(self, token=None, datastores=None):
         """Wait until certain changes occur.
 
         This methods implements a flexible and efficient long-polling
@@ -419,11 +419,11 @@ class DatastoreManager(object):
           token
             An optional token that represents a hash of the list of
             datastores, computed by the server.  If this parameter is
-            present and non-empty, ``await()`` will return when the
+            present and non-empty, ``send_await()`` will return when the
             list of datastores has changed in a way that would cause a
             different token to be computed, such as when a datastore
             is created or deleted.  The token should be obtained from
-            the previous ``await()`` call; as a special case, the
+            the previous ``send_await()`` call; as a special case, the
             value ``'.'`` forces the call to return immediately with a
             fresh token (as does any outdated token).
 
@@ -434,7 +434,7 @@ class DatastoreManager(object):
             interested in receiving updates.  If this parameter is a
             list of instances, the revision to compare is retrieved
             from each instance using :meth:`Datastore.get_rev()`.  If
-            this parameter is present and non-empty, ``await()`` will
+            this parameter is present and non-empty, ``send_await()`` will
             return whenever a new revision is available for any of
             those datastores.
 
@@ -448,7 +448,7 @@ class DatastoreManager(object):
           token
             A new token, or the value of the ``token`` parameter if
             there are no changes to the list of datastores.  You
-            should pass this to the next ``await()`` call.
+            should pass this to the next ``send_await()`` call.
 
           dsinfo
             The full list of :class:`DatastoreInfo` objects (as
@@ -465,7 +465,7 @@ class DatastoreManager(object):
             not changed (and are still valid) will not be present.
 
         Unlike :meth:`Datastore.load_deltas()` and
-        :meth:`Datastore.await_deltas()`, ``await()`` does not apply
+        :meth:`Datastore.await_deltas()`, ``send_await()`` does not apply
         the deltas returned in ``deltamap`` to the respective
         datastores; that is the caller's responsibility.  For
         example::
@@ -485,7 +485,7 @@ class DatastoreManager(object):
             else:
                 for ds in datastores:
                     cursors[ds._handle] = ds._rev
-        resp = self._dsops.await(token=token, cursors=cursors)
+        resp = self._dsops.send_await(token=token, cursors=cursors)
         dsinfos = None
         deltamap = None
         if 'list_datastores' in resp:
@@ -512,13 +512,13 @@ class DatastoreManager(object):
 
     @staticmethod
     def make_cursor_map(datastores, deltamap):
-        """Utility to construct a ``datastores`` argument for :meth:`await()`.
+        """Utility to construct a ``datastores`` argument for :meth:`send_await()`.
 
         Parameters
           datastores
             A list of :class:`Datastore` objects.
           deltamap
-            An data structure as returned by :meth:`await()` in its
+            An data structure as returned by :meth:`send_await()` in its
             ``deltamap`` return value.  This may be None or it may be
             a dict mapping :class:`Datastore` objects to values that
             are either lists of deltas or ``None``.
@@ -526,7 +526,7 @@ class DatastoreManager(object):
         Returns
           A dict mapping :class:`Datastore` objects to revisions,
           suitable to pass as the ``datastores`` parameter to
-          :meth:`await()`.  This will normally just map the datastores
+          :meth:`send_await()`.  This will normally just map the datastores
           from the ``datastores`` parameter to their current revision;
           however, datastores that are deleted or invalid according to
           ``deltamap`` are excluded from the dict, and for datastores
@@ -534,7 +534,7 @@ class DatastoreManager(object):
           is set to one higher than the revision of the last delta.
 
         Using this function will reduce redundant server roundtrips in
-        multi-threaded apps that call :meth:`await()` in a background
+        multi-threaded apps that call :meth:`send_await()` in a background
         thread and then pass the received deltas to the main thread
         through some kind of queue.
         """
@@ -1146,7 +1146,7 @@ class Datastore(object):
         """
         if self._changes:
             raise DatastoreError('Cannot call await_deltas() with pending changes')
-        resp = self._manager._dsops.await(cursors={self._handle: self._rev})
+        resp = self._manager._dsops.send_await(cursors={self._handle: self._rev})
         if 'get_deltas' not in resp:
             return {}
         subresp = resp['get_deltas']
@@ -1203,7 +1203,7 @@ class Datastore(object):
         :meth:`await_deltas()` or :meth:`load_deltas()`.
 
         The deltas should be received from the server.  Under certain
-        conditions (e.g. when :meth:`DatastoreManager.await()` is
+        conditions (e.g. when :meth:`DatastoreManager.send_await()` is
         called in a background thread) it is possible that the server
         sends a delta that has already been applied locally.  Such
         deltas are silently ignored.
