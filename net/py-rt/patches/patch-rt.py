$NetBSD: patch-rt.py,v 1.3 2020/01/02 15:46:11 leot Exp $

In RT 4 when a ticket is not modified an empty response is returned.
Treat it as a successfull operation.

--- rt.py.orig	2019-10-25 12:58:58.000000000 +0000
+++ rt.py
@@ -736,6 +736,8 @@ class Rt:
         """
         post_data = self.__ticket_post_data(kwargs)
         msg = self.__request('ticket/{}/edit'.format(str(ticket_id)), post_data={'content': post_data})
+        if "" == msg: # Ticket not modified
+            return True
         state = msg.split('\n')[2]
         return self.RE_PATTERNS['update_pattern'].match(state) is not None
 
