$NetBSD: patch-DiscID.xs,v 1.1 2025/07/04 18:54:23 wiz Exp $

Fix a bug.
https://github.com/njh/perl-musicbrainz-discid/issues/10

--- DiscID.xs.orig	2025-07-04 18:52:54.304507603 +0000
+++ DiscID.xs
@@ -113,7 +113,7 @@ discid_get_track_length( disc, track_num
 ## Provides the TOC of a known CD.
 ##
 int
-discid_put( disc, first_track, sectors, offsets ... )
+discid_put( disc, first_track, sectors, offsets, ... )
   DiscId *disc
   int first_track
   int sectors
