$NetBSD: patch-vendor_pnet__datalink-0.28.0_src_bpf.rs,v 1.1 2023/05/19 11:20:50 he Exp $

Don't assume that c_char is signed.
This applies fix from upstream:
https://github.com/libpnet/libpnet/commit/ce180d3bfe33b90ba0a68cb23802631387e3717b

--- ../vendor/pnet_datalink-0.28.0/src/bpf.rs.orig	1970-01-01 00:00:00.000000000 +0000
+++ ../vendor/pnet_datalink-0.28.0/src/bpf.rs
@@ -130,7 +130,7 @@ pub fn channel(network_interface: &Netwo
     }
     let mut iface: bpf::ifreq = unsafe { mem::zeroed() };
     for (i, c) in network_interface.name.bytes().enumerate() {
-        iface.ifr_name[i] = c as i8;
+        iface.ifr_name[i] = c as libc::c_char;
     }
 
     let buflen = config.read_buffer_size as libc::c_uint;
