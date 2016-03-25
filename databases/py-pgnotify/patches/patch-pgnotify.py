$NetBSD: patch-pgnotify.py,v 1.1 2016/03/25 21:15:07 joerg Exp $

--- pgnotify.py.orig	2016-03-25 09:35:27.000000000 +0000
+++ pgnotify.py
@@ -99,9 +99,9 @@ class pgnotify:
                 else:
                     self.pgconn.query('unlisten "%s"' % self.event)
                     self.pgconn.query('unlisten "%s"' % self.stop)
-                    raise pgnotifyError, \
+                    raise pgnotifyError(
                         'listening for ("%s", "%s") but notified of "%s"' \
-                        % (self.event, self.stop, event)
+                        % (self.event, self.stop, event))
 
 
 
