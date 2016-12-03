$NetBSD: patch-mcomix_archive_sevenzip_external.py,v 1.1 2016/12/03 04:08:53 nonaka Exp $

fix read subprocess stdout line by line.

See http://stackoverflow.com/questions/2715847/python-read-streaming-input-from-subprocess-communicate/17698359#17698359

--- mcomix/archive/sevenzip_external.py.orig	2016-02-12 18:52:12.000000000 +0000
+++ mcomix/archive/sevenzip_external.py	2016-12-03 03:47:59.108184817 +0000
@@ -112,7 +112,7 @@ class SevenZipArchive(archive_base.Exter
             self._path = None
             proc = process.popen(self._get_list_arguments(), stderr=process.STDOUT)
             try:
-                for line in proc.stdout:
+                for line in iter(proc.stdout.readline, b''):
                     filename = self._parse_list_output_line(line.rstrip(os.linesep))
                     if filename is not None:
                         yield self._unicode_filename(filename)
@@ -231,7 +231,7 @@ class TarArchive(SevenZipArchive):
         self._path = 'archive.tar'
         proc = process.popen(self._get_list_arguments(), stderr=process.STDOUT)
         try:
-            for line in proc.stdout:
+            for line in iter(proc.stdout.readline, b''):
                 self._parse_list_output_line(line.rstrip(os.linesep))
         finally:
             proc.stdout.close()
