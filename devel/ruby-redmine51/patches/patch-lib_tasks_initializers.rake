$NetBSD: patch-lib_tasks_initializers.rake,v 1.2 2023/12/14 15:35:43 taca Exp $

Generate secret_token.rb with safe mode.

--- lib/tasks/initializers.rake.orig	2023-11-27 20:30:04.000000000 +0000
+++ lib/tasks/initializers.rake
@@ -3,7 +3,7 @@ desc 'Generates a secret token for the a
 file 'config/initializers/secret_token.rb' do
   path = File.join(Rails.root, 'config', 'initializers', 'secret_token.rb')
   secret = SecureRandom.hex(40)
-  File.open(path, 'w') do |f|
+  File.open(path, 'w', 0640) do |f|
     f.write <<"EOF"
 # frozen_string_literal: true
 
