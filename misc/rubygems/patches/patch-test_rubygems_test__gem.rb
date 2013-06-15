$NetBSD: patch-test_rubygems_test__gem.rb,v 1.4 2013/06/15 02:12:48 taca Exp $

Use vendorlibdir.

--- test/rubygems/test_gem.rb.orig	2013-03-11 21:10:40.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -964,12 +964,12 @@ class TestGem < Gem::TestCase
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
