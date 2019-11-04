$NetBSD: patch-scapy_arch_bpf_supersocket.py,v 1.1 2019/11/04 05:48:26 gutteridge Exp $

Add DragonFly support.

--- scapy/arch/bpf/supersocket.py.orig	2019-08-04 16:12:30.000000000 +0000
+++ scapy/arch/bpf/supersocket.py
@@ -16,14 +16,14 @@ from scapy.arch.bpf.consts import BIOCGB
     BIOCIMMEDIATE, BIOCPROMISC, BIOCSBLEN, BIOCSETIF, BIOCSHDRCMPLT, \
     BPF_BUFFER_LENGTH, BIOCSDLT, DLT_IEEE802_11_RADIO
 from scapy.config import conf
-from scapy.consts import FREEBSD, NETBSD, DARWIN
+from scapy.consts import FREEBSD, NETBSD, DARWIN, DRAGONFLY
 from scapy.data import ETH_P_ALL
 from scapy.error import Scapy_Exception, warning
 from scapy.supersocket import SuperSocket
 from scapy.compat import raw
 
 
-if FREEBSD or NETBSD:
+if FREEBSD or NETBSD or DRAGONFLY:
     BPF_ALIGNMENT = 8  # sizeof(long)
 else:
     BPF_ALIGNMENT = 4  # sizeof(int32_t)
@@ -260,7 +260,7 @@ class L2bpfListenSocket(_L2bpfSocket):
             return
 
         # Extract useful information from the BPF header
-        if FREEBSD or NETBSD:
+        if FREEBSD or NETBSD or DRAGONFLY:
             # struct bpf_xhdr or struct bpf_hdr32
             bh_tstamp_offset = 16
         else:
