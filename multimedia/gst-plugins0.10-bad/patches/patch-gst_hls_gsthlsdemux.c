$NetBSD: patch-gst_hls_gsthlsdemux.c,v 1.1 2011/08/15 21:08:32 wiz Exp $

Fix build on NetBSD-5.0 where NULL doesn't have enough parentheses.

--- gst/hls/gsthlsdemux.c.orig	2011-05-03 13:30:13.000000000 +0000
+++ gst/hls/gsthlsdemux.c
@@ -370,14 +370,14 @@ gst_hls_demux_sink_event (GstPad * pad, 
         /* In most cases, this will happen if we set a wrong url in the
          * source element and we have received the 404 HTML response instead of
          * the playlist */
-        GST_ELEMENT_ERROR (demux, STREAM, DECODE, ("Invalid playlist."), NULL);
+        GST_ELEMENT_ERROR (demux, STREAM, DECODE, ("Invalid playlist."), (NULL));
         return FALSE;
       }
 
       if (!ret && gst_m3u8_client_is_live (demux->client)) {
         GST_ELEMENT_ERROR (demux, RESOURCE, NOT_FOUND,
             ("Failed querying the playlist uri, "
-                "required for live sources."), NULL);
+                "required for live sources."), (NULL));
         return FALSE;
       }
 
@@ -605,7 +605,7 @@ end_of_playlist:
 cache_error:
   {
     GST_ELEMENT_ERROR (demux, RESOURCE, NOT_FOUND,
-        ("Could not cache the first fragments"), NULL);
+        ("Could not cache the first fragments"), (NULL));
     gst_hls_demux_stop (demux);
     return;
   }
@@ -868,7 +868,7 @@ uri_error:
 state_change_error:
   {
     GST_ELEMENT_ERROR (demux, CORE, STATE_CHANGE,
-        ("Error changing state of the fetcher element."), NULL);
+        ("Error changing state of the fetcher element."), (NULL));
     bret = FALSE;
     goto quit;
   }
