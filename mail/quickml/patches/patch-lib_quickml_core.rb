$NetBSD: patch-lib_quickml_core.rb,v 1.2 2013/09/26 09:42:23 obache Exp $

* specify character coding system with ruby-1.9 way
* use fileutils instead of deprecated ftools

--- lib/quickml/core.rb.orig	2004-06-08 20:15:11.000000000 +0000
+++ lib/quickml/core.rb
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/core - a part of quickml server
 #
@@ -8,7 +9,6 @@
 # You can redistribute it and/or modify it under the terms of 
 # the GNU General Public License version 2.
 #
-$KCODE='e'
 require 'quickml/utils'
 require 'quickml/gettext'
 
@@ -318,7 +318,7 @@ module QuickML
     end
 
     def remove_alertedp_file
-      File.safe_unlink(@alertedp_file)
+      FileUtils.safe_unlink(@alertedp_file)
     end
 
     def _submit (mail)
@@ -545,13 +545,13 @@ module QuickML
     end
 
     def close
-      File.safe_unlink(@members_file)
-      File.safe_unlink(@count_file)
-      File.safe_unlink(@charset_file)
-      File.safe_unlink(@alertedp_file)
-      File.safe_unlink(@waiting_members_file)
-      File.safe_unlink(@waiting_message_file)
-      File.safe_unlink(@ml_config_file)
+      FileUtils.safe_unlink(@members_file)
+      FileUtils.safe_unlink(@count_file)
+      FileUtils.safe_unlink(@charset_file)
+      FileUtils.safe_unlink(@alertedp_file)
+      FileUtils.safe_unlink(@waiting_members_file)
+      FileUtils.safe_unlink(@waiting_message_file)
+      FileUtils.safe_unlink(@ml_config_file)
       @logger.log "[#{@name}]: ML Closed"
     end
 
@@ -610,8 +610,8 @@ module QuickML
         end
       }
       submit(mail)
-      File.safe_unlink(@waiting_members_file)
-      File.safe_unlink(@waiting_message_file)
+      FileUtils.safe_unlink(@waiting_members_file)
+      FileUtils.safe_unlink(@waiting_message_file)
       @logger.log "[#{@name}]: Accept confirmation: #{@addressconfirmation_address} #{@address}"
     end
 
