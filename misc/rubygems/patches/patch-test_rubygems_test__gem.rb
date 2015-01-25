$NetBSD: patch-test_rubygems_test__gem.rb,v 1.5 2015/01/25 16:13:13 taca Exp $

Use vendorlibdir.

--- test/rubygems/test_gem.rb.orig	2014-11-30 04:31:10.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -641,12 +641,12 @@ class TestGem < Gem::TestCase
   end
 
   def test_self_prefix_sitelibdir
-    orig_sitelibdir = RbConfig::CONFIG['sitelibdir']
-    RbConfig::CONFIG['sitelibdir'] = @@project_dir
+    orig_sitelibdir = RbConfig::CONFIG['vendorlibdir']
+    RbConfig::CONFIG['vendorlibdir'] = @@project_dir
 
     assert_nil Gem.prefix
   ensure
-    RbConfig::CONFIG['sitelibdir'] = orig_sitelibdir
+    RbConfig::CONFIG['vendorlibdir'] = orig_sitelibdir
   end
 
   def test_self_read_binary
