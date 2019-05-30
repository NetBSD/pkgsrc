$NetBSD: patch-signer_src_wire_edns.c,v 1.1 2019/05/30 20:04:59 he Exp $

Skip over the rest of the OPT record.
Reported as https://issues.opendnssec.org/browse/SUPPORT-242

--- signer/src/wire/edns.c.orig	2017-01-20 14:57:50.000000000 +0000
+++ signer/src/wire/edns.c
@@ -123,6 +123,7 @@ edns_rr_parse(edns_rr_type* err, buffer_
     uint16_t opt_class;
     uint8_t  opt_version;
     uint16_t opt_flags;
+    uint16_t opt_rdlen;
 
     if (!err || !buffer) {
         ods_log_debug("[%s] parse: no edns rr or no packet buffer available",
@@ -148,7 +150,8 @@ edns_rr_parse(edns_rr_type* err, buffer_
     (void)buffer_read_u8(buffer); /* opt_extended_rcode */
     opt_version = buffer_read_u8(buffer);
     opt_flags = buffer_read_u16(buffer);
-    (void)buffer_read_u16(buffer); /* opt_rdlen */
+    opt_rdlen = buffer_read_u16(buffer);
+    buffer_skip(buffer, opt_rdlen);
 
     if (opt_version != 0) {
         /* The only error is VERSION not implemented */
