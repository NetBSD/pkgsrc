$NetBSD: patch-extconf.rb,v 1.1 2017/09/18 02:36:01 taca Exp $

Use modern module name.

--- extconf.rb.orig	2009-02-01 08:31:18.000000000 +0000
+++ extconf.rb
@@ -37,9 +37,9 @@ File.open("conftest.c", "w") do |f|
   f.puts src
 end
 if defined? cpp_command then
-  cpp = Config.expand(cpp_command(''))
+  cpp = RbConfig.expand(cpp_command(''))
 else
-  cpp = Config.expand sprintf(CPP, $CPPFLAGS, $CFLAGS, '')
+  cpp = RbConfig.expand sprintf(CPP, $CPPFLAGS, $CFLAGS, '')
 end
 if /mswin32/ =~ RUBY_PLATFORM && !/-E/.match(cpp)
   cpp << " -E"
