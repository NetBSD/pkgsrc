$NetBSD: patch-mcomix_archive_archive_base.py,v 1.1 2016/12/03 04:08:53 nonaka Exp $

fix read subprocess stdout line by line.

See http://stackoverflow.com/questions/2715847/python-read-streaming-input-from-subprocess-communicate/17698359#17698359

--- mcomix/archive/archive_base.py.orig	2016-02-12 18:52:12.000000000 +0000
+++ mcomix/archive/archive_base.py	2016-12-03 03:47:22.878349500 +0000
@@ -211,7 +211,7 @@ class ExternalExecutableArchive(NonUnico
                              self._get_list_arguments() +
                              [self.archive])
         try:
-            for line in proc.stdout:
+            for line in iter(proc.stdout.readline, b''):
                 filename = self._parse_list_output_line(line.rstrip(os.linesep))
                 if filename is not None:
                     yield self._unicode_filename(filename)
