$NetBSD: patch-test_resolv_test__dns.rb,v 1.1 2025/07/13 15:32:01 taca Exp $

Update resolv gem to 0.3.1.

--- test/resolv/test_dns.rb.orig	2025-04-09 09:23:04.000000000 +0000
+++ test/resolv/test_dns.rb
@@ -589,6 +589,13 @@ class TestResolvDNS < Test::Unit::TestCa
     assert_operator(2**14, :<, m.to_s.length)
   end
 
+  def test_too_long_address
+    too_long_address_message = [0, 0, 1, 0, 0, 0].pack("n*") + "\x01x" * 129 + [0, 0, 0].pack("cnn")
+    assert_raise_with_message(Resolv::DNS::DecodeError, /name label data exceed 255 octets/) do
+      Resolv::DNS::Message.decode too_long_address_message
+    end
+  end
+
   def assert_no_fd_leak
     socket = assert_throw(self) do |tag|
       Resolv::DNS.stub(:bind_random_port, ->(s, *) {throw(tag, s)}) do
