$NetBSD: patch-lib_rdoc_parser_c.rb,v 1.1.2.2 2013/07/16 19:12:27 tron Exp $

Dirty hack for Ruby 1.8.7.

--- lib/rdoc/parser/c.rb.orig	2013-07-05 02:21:00.000000000 +0000
+++ lib/rdoc/parser/c.rb
@@ -729,6 +729,7 @@ class RDoc::Parser::C < RDoc::Parser
   def find_class_comment class_name, class_mod
     comment = nil
 
+    begin
     if @content =~ %r%
         ((?>/\*.*?\*/\s+))
         (static\s+)?
@@ -747,6 +748,29 @@ class RDoc::Parser::C < RDoc::Parser
     else
       comment = ''
     end
+    rescue RegexpError
+      if RUBY_VERSION == "1.8.7"
+        if @content =~ %r%
+            ((?>/\*.*?\*/\s+))
+            (static\s+)?
+            void\s+
+            Init_#{class_name}\s*(?:_\(\s*)?\(\s*(?:void\s*)?\)%xmi then
+          comment = $1.sub(%r%Document-(?:class|module):\s+#{class_name}%, '')
+        elsif @content =~ %r%Document-(?:class|module):\s+#{class_name}\s*?
+                             (?:<\s+[:,\w]+)?\n((?>.*?\*/))%xm then
+          comment = "/*\n#{$1}"
+        elsif @content =~ %r%((?>/\*.*?\*/\s+))
+                             ([\w\.\s]+\s* = \s+)?rb_define_(class|module).*?"(#{class_name})"%xm then
+          comment = $1
+        elsif @content =~ %r%((?>/\*.*?\*/\s+))
+                             ([\w\.\s]+\s* = \s+)?rb_define_(class|module)_under.*?"(#{class_name.split('::').last})"%xm then
+          comment = $1
+        else
+          comment = ''
+        end
+      end
+      comment = ''
+    end
 
     comment = RDoc::Comment.new comment, @top_level
     comment.normalize
