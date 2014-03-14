$NetBSD: patch-test_rubygems_test__gem.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Use vendordir instead of sitedir.

--- test/rubygems/test_gem.rb.orig	2014-02-06 02:59:36.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -560,12 +560,12 @@ class TestGem < Gem::TestCase
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
