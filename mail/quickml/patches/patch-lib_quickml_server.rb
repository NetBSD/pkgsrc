$NetBSD: patch-lib_quickml_server.rb,v 1.1 2013/09/26 09:42:23 obache Exp $

* use fileutils instead of deprecated ftools

--- lib/quickml/server.rb.orig	2004-06-07 08:50:59.000000000 +0000
+++ lib/quickml/server.rb
@@ -335,7 +335,7 @@ module QuickML
     end
 
     def remove_pid_file
-      File.safe_unlink(@config.pid_file) if Process.pid == read_pid_file
+      FileUtils.safe_unlink(@config.pid_file) if Process.pid == read_pid_file
     end
 
     public
