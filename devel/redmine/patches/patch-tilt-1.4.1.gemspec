$NetBSD: patch-tilt-1.4.1.gemspec,v 1.1 2015/03/29 08:30:02 ryoon Exp $

--- tilt-1.4.1.gemspec.orig	2015-03-29 02:21:01.000000000 +0000
+++ tilt-1.4.1.gemspec
@@ -46,7 +46,6 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<sass>, [">= 0"])
       s.add_development_dependency(%q<wikicloth>, [">= 0"])
       s.add_development_dependency(%q<yajl-ruby>, [">= 0"])
-      s.add_development_dependency(%q<rdoc>, [">= 0"])
     else
       s.add_dependency(%q<asciidoctor>, [">= 0.1.0"])
       s.add_dependency(%q<RedCloth>, [">= 0"])
