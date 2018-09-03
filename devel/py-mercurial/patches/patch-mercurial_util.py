$NetBSD: patch-mercurial_util.py,v 1.1 2018/09/03 12:46:59 joerg Exp $

Upstream 1af95139e5ec:
Avoid infinite loops during decompression for truncated input.

--- mercurial/util.py.orig	2018-08-01 14:20:18.000000000 +0000
+++ mercurial/util.py
@@ -3343,6 +3343,9 @@ class _CompressedStreamReader(object):
                 return ''.join(buf)
             chunk = self._reader(65536)
             self._decompress(chunk)
+            if not chunk and not self._pending and not self._eof:
+                # No progress and no new data, bail out
+                return ''.join(buf)
 
 class _GzipCompressedStreamReader(_CompressedStreamReader):
     def __init__(self, fh):
