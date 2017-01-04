$NetBSD: patch-tilt-1.4.1.gemspec,v 1.3 2017/01/04 23:05:12 rodent Exp $

Don' t depend on ruby-rdoc.

--- tilt-1.4.1.gemspec.orig	2016-12-14 21:00:14.176572000 +0000
+++ tilt-1.4.1.gemspec
@@ -46,7 +46,6 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<sass>, [">= 0"])
       s.add_development_dependency(%q<wikicloth>, [">= 0"])
       s.add_development_dependency(%q<yajl-ruby>, [">= 0"])
-      s.add_development_dependency(%q<rdoc>, [">= 0"])
     else
       s.add_dependency(%q<asciidoctor>, [">= 0.1.0"])
       s.add_dependency(%q<RedCloth>, [">= 0"])
