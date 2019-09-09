$NetBSD: patch-test.py,v 1.1 2019/09/09 07:09:47 maya Exp $

Port to python 3.

--- test.py.orig	2010-04-10 17:41:18.000000000 +0000
+++ test.py
@@ -9,111 +9,111 @@ import sysctl
 
 # Invalid node
 try:
-    print "Testing invalid node: sysctl.read(\"unknown\")"
+    print("Testing invalid node: sysctl.read(\"unknown\")")
     sysctl.read("unknown")
 except OSError as detail:
-    print detail
-    print "PASSED"
+    print(detail)
+    print("PASSED")
 else:
-    print "FAILED"
+    print("FAILED")
 
 # Node with Struct/Table val.
 tmp = 666 #Variable Declaration
 try:
-    print "Testing (integer) node sysctl.read(\"kern.maxproc\")"
+    print("Testing (integer) node sysctl.read(\"kern.maxproc\")")
     tmp = sysctl.read("kern.maxproc")
 except ValueError as detail:
-    print detail
-    print "FAILED"
+    print(detail)
+    print("FAILED")
 else:
-    print "kern.maxproc == %i" % tmp
-    print "PASSED"
+    print("kern.maxproc == %i" % tmp)
+    print("PASSED")
 
 # Node with String.
 try:
-    print "Testing (string) node sysctl.read(\"kern.ostype\")"
+    print("Testing (string) node sysctl.read(\"kern.ostype\")")
     tmp = sysctl.read("kern.ostype")
 except ValueError as detail:
-    print detail
-    print "FAILED"
+    print(detail)
+    print("FAILED")
 else:
-    print "kern.ostype = %s" % tmp
-    print "PASSED"
+    print("kern.ostype = %s" % tmp)
+    print("PASSED")
 
 # Node with long integer.
 try:
-    print "Testing read (long integer) node sysctl.read(\"kern.osrevision\")"
+    print("Testing read (long integer) node sysctl.read(\"kern.osrevision\")")
     tmp = sysctl.read("kern.osrevision")
 except ValueError as detail:
-    print detail
-    print "FAILED"
+    print(detail)
+    print("FAILED")
 else:
-    print "kern.osrevision = %li" % tmp
-    print "PASSED"
+    print("kern.osrevision = %li" % tmp)
+    print("PASSED")
 
 
 # Write a read-only node.
 osrev = 0
 try:
-    print "Testing write to read only node sysctl.write(\"kern.osrevision\", 2)"
+    print("Testing write to read only node sysctl.write(\"kern.osrevision\", 2)")
     osrev = sysctl.write("kern.osrevision", 2)
 except OSError as detail:
-    print detail
-    print "sysctl.write() failed."
-    print "PASSED"
+    print(detail)
+    print("sysctl.write() failed.")
+    print("PASSED")
 else:
     if osrev == sysctl.read("kern.osrevision"):
-        print "FAILED: write succeed to read-only node! (review test? )"
+        print("FAILED: write succeed to read-only node! (review test? )")
     else:
-        print "FAILED"
+        print("FAILED")
 
 # Write an integer to a writeable node.
 # Create a writeable node of type integer.
 try:
     node="mynode"
-    print "Testing write (integer) to node %s ..." % node
+    print("Testing write (integer) to node %s ..." % node)
     subprocess.call(["sysctl", "-w", "//create=%s,type=int" % node])
     oldval = sysctl.read(node)
     oldval1 = sysctl.write(node, oldval + 1)
 except ValueError as detail:
-    print detail
+    print(detail)
     subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-    print "FAILED"
+    print("FAILED")
 else:
     if oldval != oldval1:
-        print "FAILED: sysctl.write() returns incorrect old value"
+        print("FAILED: sysctl.write() returns incorrect old value")
     else:
         if (oldval1 + 1) != sysctl.read(node):
-            print "FAILED: update failed."
+            print("FAILED: update failed.")
         else:
             sysctl.write(node, oldval1);
             subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-            print "PASSED"
+            print("PASSED")
 
 # Write a string to a writeable node.
 # Create a writeable node of type string.
 try:
     node="mynode"
-    print "Testing write (string) to node %s ..." % node
+    print("Testing write (string) to node %s ..." % node)
     subprocess.call(["sysctl", "-w", "//create=%s,type=string,value=\"nothing\"" % node])
     oldstring = sysctl.read(node)
-    print "oldstring == %s" % oldstring
+    print("oldstring == %s" % oldstring)
     oldstring1 = sysctl.write(node, "FOOBAR")
-    print "write read oldstring1 == %s" % oldstring1
+    print("write read oldstring1 == %s" % oldstring1)
 except ValueError as detail:
-    print detail
+    print(detail)
     subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-    print "FAILED"
+    print("FAILED")
 else:
     if oldstring != oldstring1:
-        print "FAILED: sysctl.write() returns incorrect old string value"
+        print("FAILED: sysctl.write() returns incorrect old string value")
     else:
         if "FOOBAR" != sysctl.read(node):
-            print "FAILED: update failed."
+            print("FAILED: update failed.")
         else:
             sysctl.write(node, oldstring1);
             subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-            print "PASSED"
+            print("PASSED")
 
 # Write a string to a writeable 2-level node.
 # Create a writeable node of type string.
@@ -121,35 +121,35 @@ try:
     node="mynode"
     leaf="myleaf"
     branch = node + '.' + leaf
-    print "Testing write (string) to node %s ..." % branch
+    print("Testing write (string) to node %s ..." % branch)
     subprocess.call(["sysctl", "-w", "//create=%s,type=node,value=\"nothing\"" % node])
     subprocess.call(["sysctl", "-w", "//create=%s,type=string,value=\"nothing\"" % branch])
     oldstring = sysctl.read(branch)
-    print "oldstring == %s" % oldstring
+    print("oldstring == %s" % oldstring)
     oldstring1 = sysctl.write(branch, "FOOBAR")
-    print "write read oldstring1 == %s" % oldstring1
+    print("write read oldstring1 == %s" % oldstring1)
 except ValueError as detail:
-    print detail
+    print(detail)
     subprocess.call(["sysctl", "-w", "//destroy=%s" % branch])
     subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-    print "FAILED"
+    print("FAILED")
 else:
     if oldstring != oldstring1:
-        print "FAILED: sysctl.write() returns incorrect old string value"
+        print("FAILED: sysctl.write() returns incorrect old string value")
     else:
         if "FOOBAR" != sysctl.read(branch):
-            print "FAILED: update failed."
+            print("FAILED: update failed.")
         else:
             sysctl.write(branch, oldstring1);
             subprocess.call(["sysctl", "-w", "//destroy=%s" % branch])
             subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-            print "PASSED"
+            print("PASSED")
 
 # Create a 3-level node using sysctl.create() and delete it using
 # sysctl.destroy() 
 
 try:
-    print "Testing sysctl.create()"
+    print("Testing sysctl.create()")
     node="mynode"
     digit=node + "." + "mydigit"
     leaf=digit + "." + "myleaf"
@@ -159,7 +159,7 @@ try:
     sysctl.create(leaf, "CTLTYPE_STRING")
 # XXX: read/readwrite/permanent 
 except OSError as detail:
-    print "FAILED"
+    print("FAILED")
 
 else:
     try:
@@ -172,10 +172,10 @@ else:
         sysctl.destroy(node)
 
     except OSError as detail:
-        print "FAILED"
+        print("FAILED")
 
     else:
-        print "PASSED"
+        print("PASSED")
 
 # Create a 3-level node and delete it using sysctl.delete()
 
@@ -183,12 +183,12 @@ try:
     node="mynode"
     digit=node + "." + "mydigit"
     leaf=digit + "." + "myleaf"
-    print "Testing write (string) to node %s ..." % leaf
+    print("Testing write (string) to node %s ..." % leaf)
     subprocess.call(["sysctl", "-w", "//create=%s,type=node,value=\"nothing\"" % node])
     subprocess.call(["sysctl", "-w", "//create=%s,type=node,value=\"nothing\"" % digit])
     subprocess.call(["sysctl", "-w", "//create=%s,type=string,value=\"nothing\"" % leaf])
     oldstring = sysctl.read(leaf)
-    print "oldstring == %s" % oldstring
+    print("oldstring == %s" % oldstring)
 
     sysctl.destroy(leaf)
 
@@ -197,51 +197,51 @@ try:
         sysctl.destroy(node)
     except OSError as detail:
         # Should fail
-        print "continue test with %s" % detail
+        print("continue test with %s" % detail)
     else: 
-        print "FAILED"
+        print("FAILED")
 
     sysctl.destroy(digit)
     sysctl.destroy(node)
-    print "PASSED"
+    print("PASSED")
 
 except ValueError as detail:
-    print detail
+    print(detail)
     subprocess.call(["sysctl", "-w", "//destroy=%s" % leaf])
     subprocess.call(["sysctl", "-w", "//destroy=%s" % digit])
     subprocess.call(["sysctl", "-w", "//destroy=%s" % node])
-    print "FAILED"
+    print("FAILED")
 
 def createdestroy(nodename, type, value):
 
     if type == "CTLTYPE_STRING":
-        print "Testing string: " + value
+        print("Testing string: " + value)
     else:
         if type == "CTLTYPE_INT":
-            print "Testing integer: %d" % value
+            print("Testing integer: %d" % value)
         else:
-            print "Unknown type requested"
+            print("Unknown type requested")
             return
 
     try:
         sysctl.create(nodename, type, value)
     except OSError as detail:
-        print "Failed to create node " + nodename + detail
+        print("Failed to create node " + nodename + detail)
 
     newval = sysctl.read(nodename)
 
     if newval != value:
-        print "FAILED Value read mismatch", newval
+        print("FAILED Value read mismatch", newval)
     else:
-        print "PASSED"
+        print("PASSED")
 
     try:
         sysctl.destroy(nodename)
     except OSError as detail:
-        print "Failed to destroy node " + nodename + detail
+        print("Failed to destroy node " + nodename + detail)
 
 
 # Try creating and verifying different types of nodes.
-print "Testing writing to different types of nodes"
+print("Testing writing to different types of nodes")
 createdestroy("tnode", "CTLTYPE_STRING", "TESTSTRING")
 createdestroy("tnode", "CTLTYPE_INT", 65535)
