$NetBSD: patch-lib_rubygems_doc__manager.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Prevent access to HOME when --install-root is used.

--- lib/rubygems/doc_manager.rb.orig	2011-07-27 02:04:03.000000000 +0000
+++ lib/rubygems/doc_manager.rb
@@ -60,7 +60,7 @@ class Gem::DocManager
   ##
   # Updates the RI cache for RDoc 2 if it is installed
 
-  def self.update_ri_cache
+  def self.update_ri_cache(install_root = nil)
     load_rdoc rescue return
 
     return unless defined? RDoc::VERSION # RDoc 1 does not have VERSION
@@ -71,7 +71,7 @@ class Gem::DocManager
       :use_cache => true,
       :use_system => true,
       :use_site => true,
-      :use_home => true,
+      :use_home => (install_root == nil)? true: false,
       :use_gems => true,
       :formatter => RDoc::RI::Formatter,
     }
