$NetBSD: patch-python_vmailmgr_types.py,v 1.1 2024/02/27 19:13:44 schmonz Exp $

Port to Python 3, maintaining 2.7 compatibility.

--- python/vmailmgr/types.py.orig	2015-09-01 16:03:21.000000000 +0000
+++ python/vmailmgr/types.py
@@ -14,13 +14,12 @@
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
-import string
 import time
 
 class Limit:
     unlimited = -1
     def __init__(self, str):
-        if str[0] == '-' or string.lower(str) == 'unlimited':
+        if str[0] == '-' or str.lower() == 'unlimited':
             str = self.unlimited
         self.value = int(str)
     def __str__(self):
@@ -84,18 +83,18 @@ class VUser:
             self.from_binary(bin)
 
     def from_binary(self, bin):
-        if bin[0] <> chr(2):
-            raise ValueError, "Virtual user data has invalid format number"
+        if bin[0] != chr(2):
+            raise ValueError("Virtual user data has invalid format number")
         i = 1
-        while bin[i] <> chr(0):
+        while bin[i] != chr(0):
             flag = ord(bin[i])
             val = ord(bin[i+1])
             i = i + 2
             if flag == ATTR_MAILBOX_ENABLED:
                 self.mailbox_enabled = Flag(val)
             else:
-                raise ValueError, "Invalid flag number %d in vuser data" % flag
-        bin = string.split(bin[i+1:], '\0')
+                raise ValueError("Invalid flag number %d in vuser data" % flag)
+        bin = bin[i+1:].split('\0')
         self.password = bin[0]
         self.mailbox = bin[1]
         self.forwards = []
@@ -124,12 +123,15 @@ class VUser:
     def items(self): return self.__dict__.items()
     def dict(self): return self.__dict__
 
+def my_cmp(a, b):
+    return (a > b) - (a < b)
+
 class NamedVUser:
     def __init__(self, username, vuser):
         self.username = username
         self.vuser = vuser
     def __cmp__(self, other):
-        return cmp(self.username, other.username)
+        return my_cmp(self.username, other.username)
     def __getitem__(self, key):
         if key == 'username':
             return self.username
