$NetBSD: patch-test.rb,v 1.1 2015/05/31 15:25:41 taca Exp $

Fix build problem on Ruby 2.2 and later.

--- test.rb.orig	2009-11-04 06:51:22.000000000 +0000
+++ test.rb
@@ -12,7 +12,7 @@ commands = [
             "tcrtest.rb rcat -tout 3 -ext put 127.0.0.1 1000",
             "tcrtest.rb misc -tout 3 127.0.0.1 1000",
            ]
-rubycmd = Config::CONFIG["bindir"] + "/" + RbConfig::CONFIG['ruby_install_name']
+rubycmd = RbConfig::CONFIG["bindir"] + "/" + RbConfig::CONFIG['ruby_install_name']
 num = 1
 commands.each do |command|
   rv = system("#{rubycmd} #{command} >/dev/null")
