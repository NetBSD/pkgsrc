$NetBSD: patch-modules_afstreams_afstreams.c,v 1.1 2017/10/02 15:16:27 fhajny Exp $

Fix a mistake in the upstream commit.

--- modules/afstreams/afstreams.c.orig	2017-09-20 19:02:23.000000000 +0000
+++ modules/afstreams/afstreams.c
@@ -275,7 +275,7 @@ afstreams_sd_new(gchar *filename, Global
   log_reader_options_defaults(&self->reader_options);
   self->reader_options.parse_options.flags |= LP_LOCAL;
   self->reader_options.parse_options.flags &= ~LP_EXPECT_HOSTNAME;
-  self->reader_options.stats_level = STATS_LEVEL1;
-  self->reader_options.stats_source = SCS_SUN_STREAMS;
+  self->reader_options.super.stats_level = STATS_LEVEL1;
+  self->reader_options.super.stats_source = SCS_SUN_STREAMS;
   return &self->super.super;
 }
