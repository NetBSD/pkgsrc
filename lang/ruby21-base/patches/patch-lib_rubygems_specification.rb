$NetBSD: patch-lib_rubygems_specification.rb,v 1.3 2015/03/08 15:08:33 taca Exp $

* Allow duplicated dependencies for now.

--- lib/rubygems/specification.rb.orig	2014-02-06 02:59:36.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -2605,7 +2605,7 @@ http://opensource.org/licenses/alphabeti
 
     dependencies.each do |dep|
       if prev = seen[dep.name] then
-        raise Gem::InvalidSpecificationException, <<-MESSAGE
+        warn <<-MESSAGE
 duplicate dependency on #{dep}, (#{prev.requirement}) use:
     add_runtime_dependency '#{dep.name}', '#{dep.requirement}', '#{prev.requirement}'
         MESSAGE
