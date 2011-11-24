$NetBSD: patch-.._soap4r-ruby1.9-2.0.3.gemspec,v 1.1.1.1 2011/11/24 13:01:14 taca Exp $

Remove ".orig" files from gemspec.

--- ../soap4r-ruby1.9-2.0.3.gemspec.orig	2011-11-24 02:51:58.000000000 +0000
+++ ../soap4r-ruby1.9-2.0.3.gemspec
@@ -116,7 +116,6 @@ files:
 - lib/soap/rpc/cgistub.rb
 - lib/soap/rpc/driver.rb
 - lib/soap/rpc/element.rb
-- lib/soap/rpc/element.rb.orig
 - lib/soap/rpc/httpserver.rb
 - lib/soap/rpc/methodDef.rb
 - lib/soap/rpc/proxy.rb
@@ -230,7 +229,6 @@ files:
 - lib/xsd/ns.rb
 - lib/xsd/qname.rb
 - lib/xsd/xmlparser.rb
-- lib/xsd/xmlparser.rb.orig
 - lib/xsd/xmlparser/libxmlparser.rb
 - lib/xsd/xmlparser/parser.rb
 - lib/xsd/xmlparser/rexmlparser.rb
