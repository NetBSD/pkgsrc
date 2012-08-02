$NetBSD: patch-lib_facter_util_virtual.rb,v 1.1 2012/08/02 08:36:40 fhajny Exp $

Add support for Illumos, as per https://github.com/puppetlabs/facter/pull/249
--- lib/facter/util/virtual.rb.orig	2012-08-01 12:08:54.829488784 +0000
+++ lib/facter/util/virtual.rb
@@ -31,7 +31,7 @@ module Facter::Util::Virtual
 
   def self.vserver?
     return false unless FileTest.exists?("/proc/self/status")
-    txt = File.read("/proc/self/status")
+    txt = File.open("/proc/self/status", "rb").read
     return true if txt =~ /^(s_context|VxID):[[:blank:]]*[0-9]/
     return false
   end
