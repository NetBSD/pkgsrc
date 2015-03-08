$NetBSD: patch-test_rubygems_test__gem.rb,v 1.1 2015/03/08 16:24:55 taca Exp $

* Use vendordir instead of sitedir.

--- test/rubygems/test_gem.rb.orig	2014-12-07 00:53:01.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -641,12 +641,12 @@ class TestGem < Gem::TestCase
   end
 
   def test_self_prefix_sitelibdir
-    orig_sitelibdir = RbConfig::CONFIG['sitelibdir']
+    orig_sitelibdir = RbConfig::CONFIG['vendorlibdir']
     RbConfig::CONFIG['sitelibdir'] = @@project_dir
 
     assert_nil Gem.prefix
   ensure
-    RbConfig::CONFIG['sitelibdir'] = orig_sitelibdir
+    RbConfig::CONFIG['vendorlibdir'] = orig_sitelibdir
   end
 
   def test_self_read_binary
