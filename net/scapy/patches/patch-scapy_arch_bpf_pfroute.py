$NetBSD: patch-scapy_arch_bpf_pfroute.py,v 1.1.2.2 2026/10/11 02:45:15 maya Exp $

For NetBSD, PF_ROUTE has been 34 since 6.0 release.

--- scapy/arch/bpf/pfroute.py.orig	2025-12-25 12:31:39.000000000 +0000
+++ scapy/arch/bpf/pfroute.py	2026-10-05 13:37:48.668666558 +0000
@@ -62,7 +62,9 @@
 )
 
 # Missing attributes
-if not hasattr(socket, "PF_ROUTE"):
+if NETBSD:
+    socket.PF_ROUTE = 34
+elif not hasattr(socket, "PF_ROUTE"):
     socket.PF_ROUTE = 17
 
 # ctypes definitions
