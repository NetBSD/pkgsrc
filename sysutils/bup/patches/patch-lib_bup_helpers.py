$NetBSD: patch-lib_bup_helpers.py,v 1.1 2012/09/04 13:43:15 wiz Exp $

Survive empty GECOS name fields.
Reported-by: Alper Kanat
Tested-by: Michael Witten
Signed-off-by: Michael Witten
---
 lib/bup/helpers.py | 8 +++++---
 1 file changed, 5 insertions(+), 3 deletions(-)

--- lib/bup/helpers.py.orig	2011-06-09 03:24:45.000000000 +0000
+++ lib/bup/helpers.py
@@ -231,9 +231,11 @@ def userfullname():
     if not _userfullname:
         uid = os.getuid()
         try:
-            _userfullname = pwd.getpwuid(uid)[4].split(',')[0]
-        except KeyError:
-            _userfullname = 'user%d' % uid
+            entry = pwd.getpwuid(uid)
+            _userfullname = entry[4].split(',')[0] or entry[0]
+        finally:
+            if not _userfullname:
+              _userfullname = 'user %d' % uid
     return _userfullname
 
 
