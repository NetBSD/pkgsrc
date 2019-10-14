$NetBSD: patch-pcap-int.h,v 1.1 2019/10/14 20:10:19 triaxx Exp $

NetBSD already defines bpf_aux_data in /usr/include/net/bpf.h.

--- pcap-int.h.orig	2019-09-30 14:39:22.000000000 +0000
+++ pcap-int.h
@@ -497,6 +497,7 @@ void	sf_cleanup(pcap_t *p);
  * Linux kernel when the kernel rejects the filter (requiring us to
  * run it in userland).  It contains VLAN tag information.
  */
+#ifndef __NetBSD__
 struct bpf_aux_data {
 	u_short vlan_tag_present;
 	u_short vlan_tag;
@@ -508,6 +509,7 @@ struct bpf_aux_data {
  */
 u_int	bpf_filter_with_aux_data(const struct bpf_insn *,
     const u_char *, u_int, u_int, const struct bpf_aux_data *);
+#endif
 
 /*
  * Internal interfaces for both "pcap_create()" and routines that
