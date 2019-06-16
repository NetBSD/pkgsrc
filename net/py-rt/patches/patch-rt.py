$NetBSD: patch-rt.py,v 1.1.2.2 2019/06/16 18:10:29 spz Exp $

Backport upstream commit bb07009c4f62dd2ac393aab82fded6424eead82f
to ignore ignore possible empty lines.

--- rt.py.orig	2018-07-16 12:47:27.000000000 +0000
+++ rt.py
@@ -518,15 +518,19 @@ class Rt:
             return items
         elif Format == 's':
             items = []
-            msgs = msg.splitlines()[2:]
+            msgs = lines[2:]
             for msg in msgs:
+                if "" == msg: # Ignore blank line at the end
+                   continue
                 ticket_id, subject = msg.split(': ', 1)
                 items.append({'id': 'ticket/' + ticket_id, 'Subject': subject})
             return items
         elif Format == 'i':
             items = []
-            msgs = msg.splitlines()[2:]
+            msgs = lines[2:]
             for msg in msgs:
+                if "" == msg: # Ignore blank line at the end
+                   continue
                 _, ticket_id = msg.split('/', 1)
                 items.append({'id': 'ticket/' + ticket_id})
             return items
