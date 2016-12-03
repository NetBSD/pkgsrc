$NetBSD: patch-mcomix_archive_rar_external.py,v 1.1 2016/12/03 04:08:53 nonaka Exp $

fix read subprocess stdout line by line.

See http://stackoverflow.com/questions/2715847/python-read-streaming-input-from-subprocess-communicate/17698359#17698359

--- mcomix/archive/rar_external.py.orig	2016-02-12 18:52:12.000000000 +0000
+++ mcomix/archive/rar_external.py	2016-12-03 03:47:38.157303416 +0000
@@ -100,7 +100,7 @@ class RarArchive(archive_base.ExternalEx
             self._path = None
             proc = process.popen(self._get_list_arguments(), stderr=process.STDOUT)
             try:
-                for line in proc.stdout:
+                for line in iter(proc.stdout.readline, b''):
                     filename = self._parse_list_output_line(line.rstrip(os.linesep))
                     if filename is not None:
                         yield self._unicode_filename(filename)
