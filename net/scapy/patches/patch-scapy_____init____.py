$NetBSD: patch-scapy_____init____.py,v 1.2 2024/10/01 23:49:29 gutteridge Exp $

Supply expected version, not inconsistent date value set by upstream.
https://github.com/secdev/scapy/pull/4548

--- scapy/__init__.py.orig	2024-09-28 13:11:32.000000000 +0000
+++ scapy/__init__.py
@@ -37,7 +37,12 @@ def _parse_tag(tag):
         # remove the 'v' prefix and add a '.devN' suffix
         return '%s.dev%s' % (match.group(1), match.group(2))
     else:
-        raise ValueError('tag has invalid format')
+        match = re.match('^v?([\\d\\.]+)$', tag)
+        if match:
+            # tagged release version
+            return '%s' % (match.group(1))
+        else:
+            raise ValueError('tag has invalid format')
 
 
 def _version_from_git_archive():
