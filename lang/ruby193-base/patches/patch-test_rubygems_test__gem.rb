$NetBSD: patch-test_rubygems_test__gem.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Use vendordir instead of sitedir.

--- test/rubygems/test_gem.rb.orig	2011-08-26 01:12:57.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -821,12 +821,12 @@ class TestGem < Gem::TestCase
   end
 
   def test_self_prefix_sitelibdir
-    orig_sitelibdir = Gem::ConfigMap[:sitelibdir]
-    Gem::ConfigMap[:sitelibdir] = @@project_dir
+    orig_sitelibdir = Gem::ConfigMap[:vendorlibdir]
+    Gem::ConfigMap[:vendorlibdir] = @@project_dir
 
     assert_nil Gem.prefix
   ensure
-    Gem::ConfigMap[:sitelibdir] = orig_sitelibdir
+    Gem::ConfigMap[:vendorlibdir] = orig_sitelibdir
   end
 
   def test_self_refresh
