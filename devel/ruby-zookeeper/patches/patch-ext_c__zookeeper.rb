$NetBSD: patch-ext_c__zookeeper.rb,v 1.1 2016/01/08 12:53:11 fhajny Exp $

Use proper lib location.

--- ext/c_zookeeper.rb.orig	2013-11-06 02:37:55.023185230 +0000
+++ ext/c_zookeeper.rb
@@ -5,7 +5,7 @@ Zookeeper.require_lib(
   'zookeeper/exceptions' # zookeeper_c depends on exceptions defined in here
 )
 
-Zookeeper.require_root 'ext/zookeeper_c'
+Zookeeper.require_root 'lib/zookeeper_c'
 
 # require File.expand_path('../zookeeper_c', __FILE__)
 
