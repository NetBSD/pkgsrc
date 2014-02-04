$NetBSD: patch-src_main.c,v 1.1 2014/02/04 11:36:44 obache Exp $

insert NetBSD specific cd code

--- src/main.c.orig	2013-12-27 00:51:30.000000000 +0000
+++ src/main.c
@@ -28,7 +28,7 @@ Foundation; version 2 of the licence.
 #include <stdbool.h>
 #include <signal.h>
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
     #include <sys/cdio.h>
 #elif defined(__linux__)
     #include <linux/cdrom.h>
@@ -192,7 +192,7 @@ bool check_disc(char * cdrom)
     bool ret = false;
     int status;
     
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
     struct ioc_read_subchannel cdsc;
     struct cd_sub_channel_info data;
 #endif
@@ -229,7 +229,7 @@ bool check_disc(char * cdrom)
     static bool alreadyKnowGood = false; /* check when program just started */
     static bool alreadyCleared = true; /* no need to clear when program just started */
     
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
     bzero(&cdsc, sizeof(cdsc));
     cdsc.data = &data;
     cdsc.data_len = sizeof(data);
@@ -356,7 +356,7 @@ void eject_disc(char * cdrom)
     //~ {
         //~ ioctl(fd, CDROMCLOSETRAY, CDSL_CURRENT);
     //~ } else {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
             ioctl(fd, CDIOCALLOW);
             ioctl(fd, CDIOCEJECT);
 #elif defined(__linux__)
@@ -479,6 +479,12 @@ cddb_disc_t * read_disc(char * cdrom)
     struct ioc_read_toc_single_entry te;
     struct ioc_read_subchannel cdsc;
     struct cd_sub_channel_info data;
+#elif defined(__NetBSD__)
+    struct ioc_toc_header th;
+    struct ioc_read_toc_entry te;
+    struct cd_toc_entry toc ;
+    struct ioc_read_subchannel cdsc;
+    struct cd_sub_channel_info data;
 #elif defined(__linux__)
     struct cdrom_tochdr th;
     struct cdrom_tocentry te;
@@ -549,6 +555,60 @@ cddb_disc_t * read_disc(char * cdrom)
             }
         }
     }
+#elif defined(__NetBSD__)
+    // read disc status info
+    bzero(&cdsc,sizeof(cdsc));
+    cdsc.data = &data;
+    cdsc.data_len = sizeof(data);
+    cdsc.data_format = CD_CURRENT_POSITION;
+    cdsc.address_format = CD_MSF_FORMAT;
+    status = ioctl(fd, CDIOCREADSUBCHANNEL, (char *)&cdsc);
+    if (status >= 0)
+    {
+        // see if we can read the disc's table of contents (TOC).
+        if (ioctl(fd, CDIOREADTOCHEADER, &th) == 0)
+        {
+            debugLog("starting track: %d\n", th.starting_track);
+            debugLog("ending track: %d\n", th.ending_track);
+            
+            disc = cddb_disc_new();
+            if (disc == NULL)
+                fatalError("cddb_disc_new() failed. Out of memory?");
+            
+            te.address_format = CD_LBA_FORMAT;
+            te.data = &toc ;
+            te.data_len=sizeof(struct cd_toc_entry) ;
+            for (i=th.starting_track; i<=th.ending_track; i++)
+            {
+                te.starting_track = i;
+                if ((ioctl(fd, CDIOREADTOCENTRIES, &te)) == 0)
+                {
+                    if (te.data->control & 0x04)
+                    {
+                        // track is a DATA track. make sure its "rip" box is not checked by default
+                        track_format[i] = FALSE;
+                    } else {
+                        track_format[i] = TRUE;
+                    }
+
+                    track = cddb_track_new();
+                    if (track == NULL)
+                        fatalError("cddb_track_new() failed. Out of memory?");
+                    
+                    cddb_track_set_frame_offset(track, te.data->addr.lba+SECONDS_TO_FRAMES(2));
+                    snprintf(trackname, 9, "Track %d", i);
+                    cddb_track_set_title(track, trackname);
+                    cddb_track_set_artist(track, "Unknown Artist");
+                    cddb_disc_add_track(disc, track);
+                }
+            }
+            te.starting_track = 0xAA;
+            if (ioctl(fd, CDIOREADTOCENTRIES, &te) == 0)
+             {
+                cddb_disc_set_length(disc, (te.data->addr.lba+SECONDS_TO_FRAMES(2))/SECONDS_TO_FRAMES(1));
+            }
+        }
+    }
 #elif defined(__linux__)
     // read disc status info
     status = ioctl(fd, CDROM_DISC_STATUS, CDSL_CURRENT);
