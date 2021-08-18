$NetBSD: patch-scapy_arch_bpf_supersocket.py,v 1.5 2021/08/18 01:44:21 gutteridge Exp $

Add DragonFly support.

Fix NetBSD 32-bit architecture alignment.

Fix send() on loopback and utun devices for Darwin and FreeBSD.
https://github.com/secdev/scapy/pull/3257

--- scapy/arch/bpf/supersocket.py.orig	2021-04-18 18:36:15.000000000 +0000
+++ scapy/arch/bpf/supersocket.py
@@ -18,7 +18,7 @@ from scapy.arch.bpf.consts import BIOCGB
     BIOCIMMEDIATE, BIOCPROMISC, BIOCSBLEN, BIOCSETIF, BIOCSHDRCMPLT, \
     BPF_BUFFER_LENGTH, BIOCSDLT, DLT_IEEE802_11_RADIO
 from scapy.config import conf
-from scapy.consts import FREEBSD, NETBSD, DARWIN
+from scapy.consts import FREEBSD, NETBSD, DARWIN, DRAGONFLY
 from scapy.data import ETH_P_ALL
 from scapy.error import Scapy_Exception, warning
 from scapy.interfaces import network_name
@@ -27,10 +27,10 @@ from scapy.compat import raw
 from scapy.layers.l2 import Loopback
 
 
-if FREEBSD:
+if FREEBSD or NETBSD:
     # On 32bit architectures long might be 32bit.
     BPF_ALIGNMENT = sizeof(c_long)
-elif NETBSD:
+elif DRAGONFLY:
     BPF_ALIGNMENT = 8  # sizeof(long)
 else:
     BPF_ALIGNMENT = 4  # sizeof(int32_t)
@@ -295,6 +295,9 @@ class L2bpfListenSocket(_L2bpfSocket):
                 bh_tstamp_offset = 16
         elif NETBSD:
             # struct bpf_hdr or struct bpf_hdr32
+            bh_tstamp_offset = sizeof(c_long) * 2
+        elif DRAGONFLY:
+            # struct bpf_hdr
             bh_tstamp_offset = 16
         else:
             # struct bpf_hdr
@@ -390,14 +393,31 @@ class L3bpfSocket(L2bpfSocket):
             self.assigned_interface = iff
 
         # Build the frame
-        if self.guessed_cls == Loopback:
-            # bpf(4) man page (from macOS, but also for BSD):
-            # "A packet can be sent out on the network by writing to a bpf
-            # file descriptor. [...] Currently only writes to Ethernets and
-            # SLIP links are supported"
-            #
-            # Headers are only mentioned for reads, not writes. tuntaposx's tun
-            # device reports as a "loopback" device, but it does IP.
+        #
+        # LINKTYPE_NULL / DLT_NULL (Loopback) is a special case. From the
+        # bpf(4) man page (from macOS/Darwin, but also for BSD):
+        #
+        # "A packet can be sent out on the network by writing to a bpf file
+        # descriptor. [...] Currently only writes to Ethernets and SLIP links
+        # are supported."
+        #
+        # Headers are only mentioned for reads, not writes, and it has the
+        # name "NULL" and id=0.
+        #
+        # The _correct_ behaviour appears to be that one should add a BSD
+        # Loopback header to every sent packet. This is needed by FreeBSD's
+        # if_lo, and Darwin's if_lo & if_utun.
+        #
+        # tuntaposx appears to have interpreted "NULL" as "no headers".
+        # Thankfully its interfaces have a different name (tunX) to Darwin's
+        # if_utun interfaces (utunX).
+        #
+        # There might be other drivers which make the same mistake as
+        # tuntaposx, but these are typically provided with VPN software, and
+        # Apple are breaking these kexts in a future version of macOS... so
+        # the problem will eventually go away. They already don't work on Macs
+        # with Apple Silicon (M1).
+        if DARWIN and iff.startswith('tun') and self.guessed_cls == Loopback:
             frame = raw(pkt)
         else:
             frame = raw(self.guessed_cls() / pkt)
