$NetBSD: patch-myhdl_conversion___toVHDL.py,v 1.1 2018/12/27 16:01:54 joerg Exp $

--- myhdl/conversion/_toVHDL.py.orig	2018-12-25 21:40:10.283137098 +0000
+++ myhdl/conversion/_toVHDL.py
@@ -1838,12 +1838,12 @@ class _ConvertAlwaysSeqVisitor(_ConvertV
         senslist = self.tree.senslist
         edge = senslist[0]
         reset = self.tree.reset
-        async = reset is not None and reset.async
+        is_async = reset is not None and reset.is_async
         sigregs = self.tree.sigregs
         varregs = self.tree.varregs
         self.write("%s: process (" % self.tree.name)
         self.write(edge.sig)
-        if async:
+        if is_async:
             self.write(', ')
             self.write(reset)
         self.write(") is")
@@ -1853,7 +1853,7 @@ class _ConvertAlwaysSeqVisitor(_ConvertV
         self.writeline()
         self.write("begin")
         self.indent()
-        if not async:
+        if not is_async:
             self.writeline()
             self.write("if %s then" % edge._toVHDL())
             self.indent()
@@ -1870,7 +1870,7 @@ class _ConvertAlwaysSeqVisitor(_ConvertV
                 self.write("%s := %s;" % (n, _convertInitVal(reg, init)))
             self.dedent()
             self.writeline()
-            if async:
+            if is_async:
                 self.write("elsif %s then" % edge._toVHDL())
             else:
                 self.write("else")
@@ -1881,7 +1881,7 @@ class _ConvertAlwaysSeqVisitor(_ConvertV
             self.writeline()
             self.write("end if;")
             self.dedent()
-        if not async:
+        if not is_async:
             self.writeline()
             self.write("end if;")
             self.dedent()
