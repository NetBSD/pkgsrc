$NetBSD: patch-test_rubygems_test__gem.rb,v 1.2 2011/08/12 15:50:44 taca Exp $

Use vendorlibdir.

--- test/rubygems/test_gem.rb.orig	2011-05-26 04:01:53.000000000 +0000
+++ test/rubygems/test_gem.rb
@@ -806,13 +806,13 @@ class TestGem < Gem::TestCase
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
