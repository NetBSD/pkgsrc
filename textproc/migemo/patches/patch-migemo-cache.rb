$NetBSD: patch-migemo-cache.rb,v 1.1 2012/08/12 11:52:26 obache Exp $

--- migemo-cache.rb.orig	2001-07-14 17:38:56.000000000 +0000
+++ migemo-cache.rb
@@ -1,5 +1,4 @@
 require 'migemo'
-$KCODE="e"
 raise if ARGV[0] == nil
 dict = ARGV[0]
 static_dict = MigemoStaticDict.new(dict)
@@ -18,10 +17,10 @@ lines.each do |line|
   migemo = Migemo.new(static_dict, pattern)
   migemo.optimization = 3
   data = Marshal.dump(migemo.regex_tree)
-  output = [pattern.length].pack("N") + pattern + 
-    [data.length].pack("N") + data
+  output = [pattern.bytesize].pack("N") + pattern.dup.force_encoding("ASCII-8BIT") + 
+    [data.bytesize].pack("N") + data
   cache.print output
   index.print [idx].pack("N")
-  idx += output.length
+  idx += output.bytesize
 end
 
