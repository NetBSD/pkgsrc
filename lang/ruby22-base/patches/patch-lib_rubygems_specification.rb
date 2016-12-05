$NetBSD: patch-lib_rubygems_specification.rb,v 1.1 2016/12/05 15:02:25 taca Exp $

* Do not warn open-ended dependency unless verbose option is enabled.

--- lib/rubygems/specification.rb.orig	2014-12-25 03:37:54.000000000 +0000
+++ lib/rubygems/specification.rb
@@ -2697,11 +2697,13 @@ pessimistic dependency on #{dep} may be 
                    ", '>= #{dep_version}'"
                  end
 
-        warning <<-WARNING
+        if Gem.configuration.really_verbose
+          warning <<-WARNING
 open-ended dependency on #{dep} is not recommended
   if #{dep.name} is semantically versioned, use:
     add_#{dep.type}_dependency '#{dep.name}', '~> #{base.join '.'}'#{bugfix}
-        WARNING
+          WARNING
+        end
       end
     end
   end
