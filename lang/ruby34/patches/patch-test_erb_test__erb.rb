$NetBSD: patch-test_erb_test__erb.rb,v 1.1.2.2 2026/05/09 16:39:11 bsiegert Exp $

Update to erb 4.0.4.1 to fix CVE-2026-41316.

--- test/erb/test_erb.rb.orig	2026-03-11 09:51:47.000000000 +0000
+++ test/erb/test_erb.rb
@@ -714,6 +714,33 @@ EOS
     assert_raise(ArgumentError) {erb.result}
   end
 
+  def test_prohibited_marshal_load_def_method
+    erb = ERB.allocate
+    erb.instance_variable_set(:@src, "")
+    erb.instance_variable_set(:@lineno, 1)
+    erb.instance_variable_set(:@_init, true)
+    erb = Marshal.load(Marshal.dump(erb))
+    assert_raise(ArgumentError) {erb.def_method(Class.new, 'render')}
+  end
+
+  def test_prohibited_marshal_load_def_module
+    erb = ERB.allocate
+    erb.instance_variable_set(:@src, "")
+    erb.instance_variable_set(:@lineno, 1)
+    erb.instance_variable_set(:@_init, true)
+    erb = Marshal.load(Marshal.dump(erb))
+    assert_raise(ArgumentError) {erb.def_module}
+  end
+
+  def test_prohibited_marshal_load_def_class
+    erb = ERB.allocate
+    erb.instance_variable_set(:@src, "")
+    erb.instance_variable_set(:@lineno, 1)
+    erb.instance_variable_set(:@_init, true)
+    erb = Marshal.load(Marshal.dump(erb))
+    assert_raise(ArgumentError) {erb.def_class}
+  end
+
   def test_multi_line_comment_lineno
     erb = ERB.new(<<~EOS)
       <%= __LINE__ %>
