$NetBSD: patch-test_json_test__json.rb,v 1.1 2013/02/12 13:03:09 taca Exp $

Fix for CVE-2013-0269.

--- test/json/test_json.rb.orig	2011-08-30 02:25:32.000000000 +0000
+++ test/json/test_json.rb
@@ -4,6 +4,7 @@
 require 'test/unit'
 require File.join(File.dirname(__FILE__), 'setup_variant')
 require 'stringio'
+require 'tempfile'
 
 unless Array.method_defined?(:permutation)
   begin
@@ -263,12 +264,12 @@ class TC_JSON < Test::Unit::TestCase
   def test_generation_of_core_subclasses_with_new_to_json
     obj = SubHash2["foo" => SubHash2["bar" => true]]
     obj_json = JSON(obj)
-    obj_again = JSON(obj_json)
+    obj_again = JSON.parse(obj_json, :create_additions => true)
     assert_kind_of SubHash2, obj_again
     assert_kind_of SubHash2, obj_again['foo']
     assert obj_again['foo']['bar']
     assert_equal obj, obj_again
-    assert_equal ["foo"], JSON(JSON(SubArray2["foo"]))
+    assert_equal ["foo"], JSON(JSON(SubArray2["foo"]), :create_additions => true)
   end
 
   def test_generation_of_core_subclasses_with_default_to_json
@@ -414,6 +415,25 @@ EOT
       JSON.parse('{"foo":"bar", "baz":"quux"}', :symbolize_names => true))
   end
 
+  def test_load
+    assert_equal @hash, JSON.load(@json)
+    tempfile = Tempfile.open('json')
+    tempfile.write @json
+    tempfile.rewind
+    assert_equal @hash, JSON.load(tempfile)
+    stringio = StringIO.new(@json)
+    stringio.rewind
+    assert_equal @hash, JSON.load(stringio)
+    assert_raise(NoMethodError) { JSON.load(nil) }
+    assert_raise(JSON::ParserError) {JSON.load('') }
+  end
+
+  def test_load_with_options
+    small_hash  = JSON("foo" => 'bar')
+    symbol_hash = { :foo => 'bar' }
+    assert_equal symbol_hash, JSON.load(small_hash, nil, :symbolize_names => true)
+  end
+
   def test_load_dump
     too_deep = '[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]'
     assert_equal too_deep, JSON.dump(eval(too_deep))
