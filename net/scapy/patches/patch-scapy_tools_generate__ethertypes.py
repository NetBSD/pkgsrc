$NetBSD: patch-scapy_tools_generate__ethertypes.py,v 1.1 2019/11/05 01:02:49 gutteridge Exp $

Fix order of Python string prefix flags, so this works with 2.7.

--- scapy/tools/generate_ethertypes.py.orig	2019-08-04 16:12:30.000000000 +0000
+++ scapy/tools/generate_ethertypes.py
@@ -20,7 +20,7 @@ URL = "https://raw.githubusercontent.com
 with urllib.request.urlopen(URL) as stream:
     DATA = stream.read()
 
-reg = rb".*ETHERTYPE_([^\s]+)\s.0x([0-9A-Fa-f]+).*\/\*(.*)\*\/"
+reg = br".*ETHERTYPE_([^\s]+)\s.0x([0-9A-Fa-f]+).*\/\*(.*)\*\/"
 COMPILED = b"""#
 # Ethernet frame types
 #       This file describes some of the various Ethernet
