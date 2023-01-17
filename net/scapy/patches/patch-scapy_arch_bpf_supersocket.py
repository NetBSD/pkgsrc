$NetBSD: patch-scapy_arch_bpf_supersocket.py,v 1.6 2023/01/17 01:33:17 gutteridge Exp $

Add DragonFly support.

--- scapy/arch/bpf/supersocket.py.orig	2022-12-24 14:06:26.000000000 +0000
+++ scapy/arch/bpf/supersocket.py
@@ -33,7 +33,7 @@ from scapy.arch.bpf.consts import (
     BPF_T_NANOTIME,
 )
 from scapy.config import conf
-from scapy.consts import DARWIN, FREEBSD, NETBSD
+from scapy.consts import DARWIN, FREEBSD, NETBSD, DRAGONFLY
 from scapy.data import ETH_P_ALL, DLT_IEEE802_11_RADIO
 from scapy.error import Scapy_Exception, warning
 from scapy.interfaces import network_name
@@ -45,6 +45,6 @@ from scapy.compat import raw
-if FREEBSD or NETBSD:
+if FREEBSD or NETBSD or DRAGONFLY:
     # On 32bit architectures long might be 32bit.
     BPF_ALIGNMENT = ctypes.sizeof(ctypes.c_long)
 else:
     # DARWIN, OPENBSD
     BPF_ALIGNMENT = ctypes.sizeof(ctypes.c_int32)
@@ -56,7 +56,7 @@ if _NANOTIME:
         # actually a bpf_timespec
         _fields_ = [("tv_sec", ctypes.c_ulong),
                     ("tv_nsec", ctypes.c_ulong)]
-elif NETBSD:
+elif NETBSD or DRAGONFLY:
     class bpf_timeval(ctypes.Structure):
         _fields_ = [("tv_sec", ctypes.c_ulong),
                     ("tv_usec", ctypes.c_ulong)]
