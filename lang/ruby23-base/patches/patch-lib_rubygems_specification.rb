$NetBSD: patch-lib_rubygems_specification.rb,v 1.1 2016/12/05 15:11:57 taca Exp $

* Do not warn open-ended dependency unless verbose option is enabled.

--- lib/rubygems/specification.rb.orig	2016-08-24 15:28:23.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -2903,11 +2903,13 @@ pessimistic dependency on #{dep} may be 
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
