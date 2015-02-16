$NetBSD: patch-lib_rexml_entity.rb,v 1.1 2015/02/16 14:03:32 taca Exp $

Fix for CVE-2015-1426.

--- lib/rexml/entity.rb.orig	2009-02-05 00:03:56.000000000 +0000
+++ lib/rexml/entity.rb
@@ -138,8 +138,15 @@ module REXML
 				matches = @value.scan(PEREFERENCE_RE)
 				rv = @value.clone
 				if @parent
+                                  sum = 0
 					matches.each do |entity_reference|
 						entity_value = @parent.entity( entity_reference[0] )
+						if sum + entity_value.bytesize > Document.entity_expansion_text_limit
+                                                  raise "entity expansion has grown too large"
+                                                else
+                                                  sum += entity_value.bytesize
+                                                end
+
 						rv.gsub!( /%#{entity_reference};/um, entity_value )
 					end
 				end
