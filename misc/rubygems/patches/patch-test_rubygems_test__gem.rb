$NetBSD: patch-test_rubygems_test__gem.rb,v 1.1 2011/03/23 14:35:05 taca Exp $

--- test/rubygems/test_gem.rb.orig	2011-03-09 03:30:40.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -822,13 +822,13 @@ class TestGem < Gem::TestCase
     Gem::ConfigMap[:libdir] = orig_libdir
   end
 
-  def test_self_prefix_sitelibdir
-    orig_sitelibdir = Gem::ConfigMap[:sitelibdir]
-    Gem::ConfigMap[:sitelibdir] = @@project_dir
+  def test_self_prefix_vendorlibdir
+    orig_vendorlibdir = Gem::ConfigMap[:vendorlibdir]
+    Gem::ConfigMap[:vendorlibdir] = @@project_dir
 
     assert_nil Gem.prefix
   ensure
-    Gem::ConfigMap[:sitelibdir] = orig_sitelibdir
+    Gem::ConfigMap[:vendorlibdir] = orig_vendorlibdir
   end
 
   def test_self_refresh
