$NetBSD: patch-lib_rubygems_specification.rb,v 1.1 2017/06/18 13:45:11 taca Exp $

* Do not warn open-ended dependency unless verbose option is enabled.

--- lib/rubygems/specification.rb.orig	2017-03-17 04:44:13.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -2909,11 +2909,13 @@ pessimistic dependency on #{dep} may be 
                    ", '>= #{dep_version}'"
                  end
 
-        warning_messages << <<-WARNING
+        if Gem.configuration.really_verbose
+          warning_messages << <<-WARNING
 open-ended dependency on #{dep} is not recommended
   if #{dep.name} is semantically versioned, use:
     add_#{dep.type}_dependency '#{dep.name}', '~> #{base.join '.'}'#{bugfix}
-        WARNING
+          WARNING
+        end
       end
     end
     if error_messages.any?
