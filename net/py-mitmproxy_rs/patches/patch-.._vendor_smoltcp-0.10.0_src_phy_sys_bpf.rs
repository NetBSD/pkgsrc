$NetBSD: patch-.._vendor_smoltcp-0.10.0_src_phy_sys_bpf.rs,v 1.1 2024/01/06 23:24:03 leot Exp $

Add support for NetBSD.

Shared upstream via <https://github.com/smoltcp-rs/smoltcp/pull/883>.

--- ../vendor/smoltcp-0.10.0/src/phy/sys/bpf.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/smoltcp-0.10.0/src/phy/sys/bpf.rs
@@ -9,16 +9,16 @@ use crate::phy::Medium;
 use crate::wire::ETHERNET_HEADER_LEN;
 
 /// set interface
-#[cfg(any(target_os = "macos", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "netbsd", target_os = "openbsd"))]
 const BIOCSETIF: libc::c_ulong = 0x8020426c;
 /// get buffer length
-#[cfg(any(target_os = "macos", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "netbsd", target_os = "openbsd"))]
 const BIOCGBLEN: libc::c_ulong = 0x40044266;
 /// set immediate/nonblocking read
-#[cfg(any(target_os = "macos", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "netbsd", target_os = "openbsd"))]
 const BIOCIMMEDIATE: libc::c_ulong = 0x80044270;
 /// set bpf_hdr struct size
-#[cfg(target_os = "macos")]
+#[cfg(any(target_os = "macos", target_os = "netbsd"))]
 const SIZEOF_BPF_HDR: usize = 18;
 /// set bpf_hdr struct size
 #[cfg(target_os = "openbsd")]
@@ -26,7 +26,7 @@ const SIZEOF_BPF_HDR: usize = 24;
 /// The actual header length may be larger than the bpf_hdr struct due to aligning
 /// see https://github.com/openbsd/src/blob/37ecb4d066e5566411cc16b362d3960c93b1d0be/sys/net/bpf.c#L1649
 /// and https://github.com/apple/darwin-xnu/blob/8f02f2a044b9bb1ad951987ef5bab20ec9486310/bsd/net/bpf.c#L3580
-#[cfg(any(target_os = "macos", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "netbsd", target_os = "openbsd"))]
 const BPF_HDRLEN: usize = (((SIZEOF_BPF_HDR + ETHERNET_HEADER_LEN) + mem::align_of::<u32>() - 1)
     & !(mem::align_of::<u32>() - 1))
     - ETHERNET_HEADER_LEN;
@@ -164,7 +164,7 @@ mod test {
     use super::*;
 
     #[test]
-    #[cfg(target_os = "macos")]
+    #[cfg(any(target_os = "macos", target_os = "netbsd"))]
     fn test_aligned_bpf_hdr_len() {
         assert_eq!(18, BPF_HDRLEN);
     }
