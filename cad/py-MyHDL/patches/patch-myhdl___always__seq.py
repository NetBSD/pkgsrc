$NetBSD: patch-myhdl___always__seq.py,v 1.1 2018/12/27 16:01:54 joerg Exp $

--- myhdl/_always_seq.py.orig	2018-12-25 21:39:40.951802739 +0000
+++ myhdl/_always_seq.py
@@ -45,7 +45,7 @@ _error.EmbeddedFunction = "embedded func
 
 class ResetSignal(_Signal):
 
-    def __init__(self, val, active, async):
+    def __init__(self, val, active, is_async):
         """ Construct a ResetSignal.
 
         This is to be used in conjunction with the always_seq decorator,
@@ -53,7 +53,7 @@ class ResetSignal(_Signal):
         """
         _Signal.__init__(self, bool(val))
         self.active = bool(active)
-        self.async = async
+        self.is_async = is_async
 
 
 def always_seq(edge, reset):
@@ -91,8 +91,8 @@ class _AlwaysSeq(_Always):
         if reset is not None:
             self.genfunc = self.genfunc_reset
             active = self.reset.active
-            async = self.reset.async
-            if async:
+            is_async = self.reset.is_async
+            if is_async:
                 if active:
                     senslist.append(reset.posedge)
                 else:
