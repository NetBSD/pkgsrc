$NetBSD: patch-.bundle_gems_net-imap-0.3.9_net-imap.gemspec,v 1.1 2025/07/26 06:21:35 taca Exp $

lib/net/imap.rb is encoded in UTF-8.  This is fixed by net-imap 0.5.9.

--- .bundle/gems/net-imap-0.3.9/net-imap.gemspec.orig	2025-07-24 08:27:20.000000000 +0000
+++ .bundle/gems/net-imap-0.3.9/net-imap.gemspec
@@ -2,7 +2,7 @@
 
 name = File.basename(__FILE__, ".gemspec")
 version = ["lib", Array.new(name.count("-"), "..").join("/")].find do |dir|
-  break File.foreach(File.join(__dir__, dir, "#{name.tr('-', '/')}.rb")) do |line|
+  break File.foreach(File.join(__dir__, dir, "#{name.tr('-', '/')}.rb"), :encoding=> 'utf-8') do |line|
     /^\s*VERSION\s*=\s*"(.*)"/ =~ line and break $1
   end rescue nil
 end
