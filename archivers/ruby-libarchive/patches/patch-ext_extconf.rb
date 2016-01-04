$NetBSD: patch-ext_extconf.rb,v 1.1 2016/01/04 02:48:05 taca Exp $

* Avoid to index by rdoc.

--- ext/extconf.rb.orig	2016-01-04 02:44:40.000000000 +0000
+++ ext/extconf.rb
@@ -7,4 +7,5 @@ if system('/bin/sh configure') and have_
   have_header('bzlib.h')
 
   create_makefile('rblibarchive')
+  FileUtils.rm_f %w(config.log config.status)
 end
