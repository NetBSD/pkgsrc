$NetBSD: patch-scapy_arch_bpf_supersocket.py,v 1.3 2021/03/23 02:03:11 gutteridge Exp $

Add DragonFly support.
Fix NetBSD 32-bit architecture alignment.

--- scapy/arch/bpf/supersocket.py.orig	2020-09-02 11:26:21.000000000 +0000
+++ scapy/arch/bpf/supersocket.py
@@ -18,18 +18,16 @@ from scapy.arch.bpf.consts import BIOCGB
     BIOCIMMEDIATE, BIOCPROMISC, BIOCSBLEN, BIOCSETIF, BIOCSHDRCMPLT, \
     BPF_BUFFER_LENGTH, BIOCSDLT, DLT_IEEE802_11_RADIO
 from scapy.config import conf
-from scapy.consts import FREEBSD, NETBSD, DARWIN
+from scapy.consts import FREEBSD, NETBSD, DARWIN, DRAGONFLY
 from scapy.data import ETH_P_ALL
 from scapy.error import Scapy_Exception, warning
 from scapy.supersocket import SuperSocket
 from scapy.compat import raw
 
 
-if FREEBSD:
+if FREEBSD or NETBSD or DRAGONFLY:
     # On 32bit architectures long might be 32bit.
     BPF_ALIGNMENT = sizeof(c_long)
-elif NETBSD:
-    BPF_ALIGNMENT = 8  # sizeof(long)
 else:
     BPF_ALIGNMENT = 4  # sizeof(int32_t)
 
@@ -283,6 +281,9 @@ class L2bpfListenSocket(_L2bpfSocket):
                 bh_tstamp_offset = 16
         elif NETBSD:
             # struct bpf_hdr or struct bpf_hdr32
+            bh_tstamp_offset = sizeof(c_long) * 2
+        elif DRAGONFLY:
+            # struct bpf_hdr
             bh_tstamp_offset = 16
         else:
             # struct bpf_hdr
