$NetBSD: patch-trs_disk.c,v 1.1 2013/01/12 19:07:56 is Exp $

--- trs_disk.c.orig	2009-06-16 00:06:25.000000000 +0000
+++ trs_disk.c
@@ -849,8 +849,8 @@ trs_disk_change(int drive)
   } else if (d->emutype == DMK) {
     fseek(d->file, DMK_NTRACKS, 0);
     d->u.dmk.ntracks = (unsigned char) getc(d->file);
-    d->u.dmk.tracklen = (unsigned char) getc(d->file) +
-      (((unsigned char) getc(d->file)) << 8);
+    d->u.dmk.tracklen  =  (unsigned char) getc(d->file);
+    d->u.dmk.tracklen += ((unsigned char) getc(d->file)) << 8;
     c = getc(d->file);
     d->u.dmk.nsides = (c & DMK_SSIDE_OPT) ? 1 : 2;
     d->u.dmk.sden = (c & DMK_SDEN_OPT) != 0;
