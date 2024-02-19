$NetBSD: patch-lib_exabgp_reactor_api_command_limit.py,v 1.1 2024/02/19 12:54:09 he Exp $

Allow "neighbor *" in route announce command, to match
"all configured neighbors".
Ref. https://github.com/Exa-Networks/exabgp/issues/1179

--- lib/exabgp/reactor/api/command/limit.py.orig	2024-02-19 12:41:58.477150474 +0000
+++ lib/exabgp/reactor/api/command/limit.py
@@ -63,6 +63,8 @@ def extract_neighbors(command):
 
 def match_neighbor(description, name):
     for string in description:
+        if string.strip() == 'neighbor *':
+            return True
         if re.search(r'(^|\s)%s($|\s|,)' % re.escape(string), name) is None:
             return False
     return True
