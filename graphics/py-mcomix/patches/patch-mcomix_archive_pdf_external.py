$NetBSD: patch-mcomix_archive_pdf_external.py,v 1.1 2016/12/03 04:08:53 nonaka Exp $

fix read subprocess stdout line by line.

See http://stackoverflow.com/questions/2715847/python-read-streaming-input-from-subprocess-communicate/17698359#17698359

--- mcomix/archive/pdf_external.py.orig	2016-02-12 18:52:12.000000000 +0000
+++ mcomix/archive/pdf_external.py	2016-12-03 03:47:31.069776589 +0000
@@ -34,7 +34,7 @@ class PdfArchive(archive_base.BaseArchiv
     def iter_contents(self):
         proc = process.popen(_mutool_exec + ['show', '--', self.archive, 'pages'])
         try:
-            for line in proc.stdout:
+            for line in iter(proc.stdout.readline, b''):
                 if line.startswith('page '):
                     yield line.split()[1] + '.png'
         finally:
@@ -52,7 +52,7 @@ class PdfArchive(archive_base.BaseArchiv
         try:
             max_size = 0
             max_dpi = PDF_RENDER_DPI_DEF
-            for line in proc.stdout:
+            for line in iter(proc.stdout.readline, b''):
                 match = self._fill_image_regex.match(line)
                 if not match:
                     continue
