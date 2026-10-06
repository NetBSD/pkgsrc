$NetBSD: patch-scapy_arch_bpf_supersocket.py,v 1.8 2026/10/06 09:54:31 leot Exp $

Add DragonFly support.

--- scapy/arch/bpf/supersocket.py.orig	2026-10-02 16:14:41.000000000 +0000
+++ scapy/arch/bpf/supersocket.py
@@ -35,7 +35,7 @@ from scapy.config import conf
     BPF_T_NANOTIME,
 )
 from scapy.config import conf
-from scapy.consts import DARWIN, FREEBSD, NETBSD
+from scapy.consts import DARWIN, FREEBSD, NETBSD, DRAGONFLY
 from scapy.data import ETH_P_ALL, DLT_IEEE802_11_RADIO
 from scapy.error import Scapy_Exception, warning
 from scapy.interfaces import network_name, _GlobInterfaceType
@@ -56,7 +56,7 @@ if TYPE_CHECKING:
 
 # Structures & c types
 
-if FREEBSD or NETBSD:
+if FREEBSD or NETBSD or DRAGONFLY:
     # On 32bit architectures long might be 32bit.
     BPF_ALIGNMENT = ctypes.sizeof(ctypes.c_long)
 else:
@@ -71,7 +71,7 @@ if _NANOTIME:
         # actually a bpf_timespec
         _fields_ = [("tv_sec", ctypes.c_int64),
                     ("tv_nsec", ctypes.c_uint64)]
-elif NETBSD:
+elif NETBSD or DRAGONFLY:
     class bpf_timeval(ctypes.Structure):
         _fields_ = [("tv_sec", ctypes.c_ulong),
                     ("tv_usec", ctypes.c_ulong)]
