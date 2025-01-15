$NetBSD: patch-src_lib_asiolink_io__address.cc,v 1.1 2025/01/15 06:05:14 wiz Exp $

Fix build with boost 1.87.
https://github.com/isc-projects/kea/pull/143

--- src/lib/asiolink/io_address.cc.orig	2024-07-25 08:50:58.000000000 +0000
+++ src/lib/asiolink/io_address.cc
@@ -37,7 +37,7 @@ IOAddress::Hash::operator()(const IOAddr
 // because we'd like to throw our own exception on failure.
 IOAddress::IOAddress(const std::string& address_str) {
     boost::system::error_code err;
-    asio_address_ = ip::address::from_string(address_str, err);
+    asio_address_ = ip::make_address(address_str, err);
     if (err) {
         isc_throw(IOError, "Failed to convert string to address '"
                   << address_str << "': " << err.message());
@@ -116,7 +116,7 @@ IOAddress::isV6Multicast() const {
 uint32_t
 IOAddress::toUint32() const {
     if (asio_address_.is_v4()) {
-        return (asio_address_.to_v4().to_ulong());
+        return (asio_address_.to_v4().to_uint());
     } else {
         isc_throw(BadValue, "Can't convert " << toText()
                   << " address to IPv4.");
