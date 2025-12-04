$NetBSD: patch-dnsdist-protobuf.cc,v 1.1 2025/12/04 23:18:59 wiz Exp $

Fix: https://github.com/PowerDNS/pdns/pull/16584

--- dnsdist-protobuf.cc
+++ dnsdist-protobuf.cc
@@ -25,6 +25,7 @@
 #include "base64.hh"
 #include "dnsdist.hh"
 #include "dnsdist-protobuf.hh"
+#include "dolog.hh"
 #include "protozero.hh"
 
 DNSDistProtoBufMessage::DNSDistProtoBufMessage(const DNSQuestion& dnsquestion) :
