$NetBSD: patch-test_rubygems_test__gem.rb,v 1.1.6.1 2022/11/30 17:19:03 bsiegert Exp $

* Use vendordir instead of sitedir.

--- test/rubygems/test_gem.rb.orig	2022-11-24 10:20:31.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -1004,12 +1004,12 @@ class TestGem < Gem::TestCase
   end
 
   def test_self_prefix_sitelibdir
-    orig_sitelibdir = RbConfig::CONFIG["sitelibdir"]
+    orig_sitelibdir = RbConfig::CONFIG["vendorlibdir"]
     RbConfig::CONFIG["sitelibdir"] = PROJECT_DIR
 
     assert_nil Gem.prefix
   ensure
-    RbConfig::CONFIG["sitelibdir"] = orig_sitelibdir
+    RbConfig::CONFIG["vendorlibdir"] = orig_sitelibdir
   end
 
   def test_self_read_binary
