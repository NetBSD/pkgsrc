$NetBSD: patch-hw_scsi_scsi-disk.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Fill in more of SCSI disk block size reports to guest. Allows use of
sector sizes outside range of 256 to 32768.

--- hw/scsi/scsi-disk.c.orig	2020-08-11 19:17:15.000000000 +0000
+++ hw/scsi/scsi-disk.c
@@ -1293,9 +1293,9 @@ static int scsi_disk_emulate_mode_sense(
         p[2] = (nb_sectors >> 8) & 0xff;
         p[3] = nb_sectors & 0xff;
         p[4] = 0; /* reserved */
-        p[5] = 0; /* bytes 5-7 are the sector size in bytes */
-        p[6] = s->qdev.blocksize >> 8;
-        p[7] = 0;
+        p[5] = (s->qdev.blocksize >> 16) & 0xff; /* bytes 5-7 are the sector size in bytes */
+        p[6] = (s->qdev.blocksize >> 8) & 0xff;
+        p[7] = s->qdev.blocksize & 0xff;
         p += 8;
     }
 
@@ -1993,10 +1993,10 @@ static int32_t scsi_disk_emulate_command
         outbuf[1] = (nb_sectors >> 16) & 0xff;
         outbuf[2] = (nb_sectors >> 8) & 0xff;
         outbuf[3] = nb_sectors & 0xff;
-        outbuf[4] = 0;
-        outbuf[5] = 0;
-        outbuf[6] = s->qdev.blocksize >> 8;
-        outbuf[7] = 0;
+        outbuf[4] = (s->qdev.blocksize >> 24) & 0xff;;
+        outbuf[5] = (s->qdev.blocksize >> 16) & 0xff;
+        outbuf[6] = (s->qdev.blocksize >> 8) & 0xff;
+        outbuf[7] = s->qdev.blocksize & 0xff;;
         break;
     case REQUEST_SENSE:
         /* Just return "NO SENSE".  */
@@ -2062,10 +2062,10 @@ static int32_t scsi_disk_emulate_command
             outbuf[5] = (nb_sectors >> 16) & 0xff;
             outbuf[6] = (nb_sectors >> 8) & 0xff;
             outbuf[7] = nb_sectors & 0xff;
-            outbuf[8] = 0;
-            outbuf[9] = 0;
-            outbuf[10] = s->qdev.blocksize >> 8;
-            outbuf[11] = 0;
+            outbuf[8] = (s->qdev.blocksize >> 24) & 0xff;
+            outbuf[9] = (s->qdev.blocksize >> 16) & 0xff;
+            outbuf[10] = (s->qdev.blocksize >> 8) & 0xff;
+            outbuf[11] = s->qdev.blocksize & 0xff;
             outbuf[12] = 0;
             outbuf[13] = get_physical_block_exp(&s->qdev.conf);
 
