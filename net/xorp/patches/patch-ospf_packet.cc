$NetBSD: patch-ospf_packet.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- ospf/packet.cc.orig	2013-04-29 19:23:06.000000000 +0000
+++ ospf/packet.cc
@@ -272,7 +272,7 @@ Packet::decode_standard_header(uint8_t *
     switch(version) {
     case OspfTypes::V2:
 	// Verify the auth structure is the correct size.
-	static_assert(sizeof(_auth) == (64 / 8));
+	my_static_assert(sizeof(_auth) == (64 / 8));
 	set_auth_type(extract_16(&ptr[Packet::AUTH_TYPE_OFFSET]));
 	memcpy(&_auth[0], &ptr[Packet::AUTH_PAYLOAD_OFFSET], sizeof(_auth));
 	// The authentication field is expected to be zero for the
