$NetBSD: patch-writecap_pcapio.c,v 1.1 2025/10/09 14:43:44 adam Exp $

Fix build on NetBSD.

--- writecap/pcapio.c.orig	2025-10-09 14:17:34.142800083 +0000
+++ writecap/pcapio.c
@@ -438,7 +438,7 @@ write_to_file(pcapio_writer* pfile, cons
         default:
             nwritten = fwrite(data, data_length, 1, pfile->fh);
             if (nwritten != 1) {
-                if (ferror(pfile->fh)) {
+                if (ferror((FILE *)pfile->fh)) {
                     *err = errno;
                 } else {
                     *err = WTAP_ERR_SHORT_WRITE;
