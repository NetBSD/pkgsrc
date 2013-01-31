$NetBSD: patch-test_rubygems_test__gem.rb,v 1.2 2013/01/31 15:56:14 taca Exp $

Use vendordir instead of sitedir.

--- test/rubygems/test_gem.rb.orig	2012-04-19 22:43:16.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -844,12 +844,12 @@ class TestGem < Gem::TestCase
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
