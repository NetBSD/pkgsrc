$NetBSD: patch-test_stringio_test__stringio.rb,v 1.1 2024/03/23 14:28:48 taca Exp $

Update stringio to 3.0.1.2 to fix for CVE-2024-27280.

--- test/stringio/test_stringio.rb.orig	2023-03-30 10:53:51.000000000 +0000
+++ test/stringio/test_stringio.rb
@@ -759,6 +759,15 @@ class TestStringIO < Test::Unit::TestCas
     assert_equal("b""\0""a", s.string)
   end
 
+  def test_ungetc_fill
+    count = 100
+    s = StringIO.new
+    s.print 'a' * count
+    s.ungetc('b' * (count * 5))
+    assert_equal((count * 5), s.string.size)
+    assert_match(/\Ab+\z/, s.string)
+  end
+
   def test_ungetbyte_pos
     b = '\\b00010001 \\B00010001 \\b1 \\B1 \\b000100011'
     s = StringIO.new( b )
@@ -784,6 +793,15 @@ class TestStringIO < Test::Unit::TestCas
     assert_equal("b""\0""a", s.string)
   end
 
+  def test_ungetbyte_fill
+    count = 100
+    s = StringIO.new
+    s.print 'a' * count
+    s.ungetbyte('b' * (count * 5))
+    assert_equal((count * 5), s.string.size)
+    assert_match(/\Ab+\z/, s.string)
+  end
+
   def test_frozen
     s = StringIO.new
     s.freeze
@@ -827,18 +845,17 @@ class TestStringIO < Test::Unit::TestCas
   end
 
   def test_overflow
-    omit if RbConfig::SIZEOF["void*"] > RbConfig::SIZEOF["long"]
+    return if RbConfig::SIZEOF["void*"] > RbConfig::SIZEOF["long"]
     limit = RbConfig::LIMITS["INTPTR_MAX"] - 0x10
     assert_separately(%w[-rstringio], "#{<<-"begin;"}\n#{<<-"end;"}")
     begin;
       limit = #{limit}
       ary = []
-      while true
+      begin
         x = "a"*0x100000
         break if [x].pack("p").unpack("i!")[0] < 0
         ary << x
-        omit if ary.size > 100
-      end
+      end while ary.size <= 100
       s = StringIO.new(x)
       s.gets("xxx", limit)
       assert_equal(0x100000, s.pos)
