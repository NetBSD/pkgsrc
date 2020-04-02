$NetBSD: patch-src_input_input__cdda.c,v 1.1 2020/04/02 15:52:46 nia Exp $

Fix syntax.

--- src/input/input_cdda.c.orig	2019-12-13 20:47:50.000000000 +0000
+++ src/input/input_cdda.c
@@ -874,7 +874,7 @@ static cdrom_toc_t *read_cdrom_toc (int 
   toc->toc_entries[i].track_mode = (tocentry.data->control & 0x04) ? 1 : 0;
   toc->toc_entries[i].first_frame_minute = tocentry.data->addr.msf.minute;
   toc->toc_entries[i].first_frame_second = tocentry.data->addr.msf.second;
-  toc->toc_entries[i]..first_frame_frame = tocentry.data->addr.msf.frame;
+  toc->toc_entries[i].first_frame_frame = tocentry.data->addr.msf.frame;
   toc->toc_entries[i].first_frame =
     (tocentry.data->addr.msf.minute * CD_SECONDS_PER_MINUTE * CD_FRAMES_PER_SECOND) +
     (tocentry.data->addr.msf.second * CD_FRAMES_PER_SECOND) +
