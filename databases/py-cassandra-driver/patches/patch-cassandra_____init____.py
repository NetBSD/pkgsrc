$NetBSD: patch-cassandra_____init____.py,v 1.1 2017/06/14 14:19:02 fhajny Exp $

Bring internal version in sync with distfile.

--- cassandra/__init__.py.orig	2017-05-24 17:32:09.000000000 +0000
+++ cassandra/__init__.py
@@ -22,7 +22,7 @@ class NullHandler(logging.Handler):
 
 logging.getLogger('cassandra').addHandler(NullHandler())
 
-__version_info__ = (3, 10)
+__version_info__ = (3, 10, 0)
 __version__ = '.'.join(map(str, __version_info__))
 
 
