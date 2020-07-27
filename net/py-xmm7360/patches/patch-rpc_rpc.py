$NetBSD: patch-rpc_rpc.py,v 1.1 2020/07/27 14:11:16 jdolecek Exp $

--- rpc/rpc.py.orig	2020-01-15 00:30:10.000000000 +0000
+++ rpc/rpc.py
@@ -7,8 +7,8 @@ import struct
 import itertools
 import ipaddress
 import hashlib
-import rpc_call_ids
-import rpc_unsol_table
+from .rpc_call_ids import call_ids
+from .rpc_unsol_table import xmm7360_unsol
 
 def asn_int4(val):
     return b'\x02\x04' + struct.pack('>L', val)
@@ -29,7 +29,7 @@ class XMMRPC(object):
         desc = resp['type']
 
         if resp['type'] == 'unsolicited':
-            name = rpc_unsol_table.xmm7360_unsol.get(resp['code'], '0x%02x' % resp['code'])
+            name = xmm7360_unsol.get(resp['code'], '0x%02x' % resp['code'])
             desc = 'unsolicited: %s' % name
             self.handle_unsolicited(resp)
 
@@ -107,7 +107,7 @@ class XMMRPC(object):
         return {'tid': txid, 'type': t, 'code': code, 'body': body, 'content': content}
 
     def handle_unsolicited(self, message):
-        name = rpc_unsol_table.xmm7360_unsol.get(message['code'], None)
+        name = xmm7360_unsol.get(message['code'], None)
 
         if name == 'UtaMsNetIsAttachAllowedIndCb':
             self.attach_allowed = message['content'][2]
@@ -322,7 +322,7 @@ def UtaModeSet(rpc, mode):
     while True:
         msg = rpc.pump()
         # msg['txid'] will be mode_tid as well
-        if rpc_unsol_table.xmm7360_unsol.get(msg['code'], None) == 'UtaModeSetRspCb':
+        if xmm7360_unsol.get(msg['code'], None) == 'UtaModeSetRspCb':
             if msg['content'][0] != mode:
                 raise IOError("UtaModeSet was not able to set mode. FCC lock enabled?")
             return
