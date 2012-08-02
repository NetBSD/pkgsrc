$NetBSD: patch-spec_unit_util__virtual_spec.rb,v 1.1 2012/08/02 08:36:40 fhajny Exp $

Add support for Illumos, as per https://github.com/puppetlabs/facter/pull/249
--- spec/unit/util/virtual_spec.rb.orig	2012-08-01 12:08:54.859082399 +0000
+++ spec/unit/util/virtual_spec.rb
@@ -2,6 +2,7 @@
 
 require 'spec_helper'
 require 'facter/util/virtual'
+require 'stringio'
 
 describe Facter::Util::Virtual do
 
@@ -64,19 +65,19 @@ describe Facter::Util::Virtual do
 
   it "should detect vserver when vxid present in process status" do
     FileTest.stubs(:exists?).with("/proc/self/status").returns(true)
-    File.stubs(:read).with("/proc/self/status").returns("VxID: 42\n")
+    File.stubs(:open).with("/proc/self/status", "rb").returns(StringIO.new("VxID: 42\n"))
     Facter::Util::Virtual.should be_vserver
   end
 
   it "should detect vserver when s_context present in process status" do
     FileTest.stubs(:exists?).with("/proc/self/status").returns(true)
-    File.stubs(:read).with("/proc/self/status").returns("s_context: 42\n")
+    File.stubs(:open).with("/proc/self/status", "rb").returns(StringIO.new("s_context: 42\n"))
     Facter::Util::Virtual.should be_vserver
   end
 
   it "should not detect vserver when vserver flags not present in process status" do
     FileTest.stubs(:exists?).with("/proc/self/status").returns(true)
-    File.stubs(:read).with("/proc/self/status").returns("wibble: 42\n")
+    File.stubs(:open).with("/proc/self/status", "rb").returns(StringIO.new("wibble: 42\n"))
     Facter::Util::Virtual.should_not be_vserver
   end
 
@@ -94,7 +95,7 @@ describe Facter::Util::Virtual do
       it "should detect vserver as #{expected.inspect}" do
         status = File.read(status_file)
         FileTest.stubs(:exists?).with("/proc/self/status").returns(true)
-        File.stubs(:read).with("/proc/self/status").returns(status)
+        File.stubs(:open).with("/proc/self/status", "rb").returns(StringIO.new(status))
         Facter::Util::Virtual.vserver?.should == expected
       end
     end
