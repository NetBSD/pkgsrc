$NetBSD: patch-lib__rb__setup.rb,v 1.1 2011/06/03 13:39:45 fhajny Exp $

pkgsrc prefers vendor Ruby dirs.
--- lib/rb/setup.rb.orig	2011-01-31 01:13:14.000000000 +0000
+++ lib/rb/setup.rb
@@ -165,9 +165,9 @@ class ConfigTable
       libruby         = "#{c['prefix']}/lib/ruby"
       librubyver      = c['rubylibdir']
       librubyverarch  = c['archdir']
-      siteruby        = c['sitedir']
-      siterubyver     = c['sitelibdir']
-      siterubyverarch = c['sitearchdir']
+      siteruby        = c['vendordir']
+      siterubyver     = c['vendorlibdir']
+      siterubyverarch = c['vendorarchdir']
     elsif newpath_p
       # 1.4.4 <= V <= 1.6.3
       libruby         = "#{c['prefix']}/lib/ruby"
