$NetBSD: patch-src_spectro__source.cc,v 1.1 2023/05/24 22:42:53 he Exp $

`role_t` isn't exactly the same as `int`, causing -Wformat
warnings.  Cast to `int` before printing with %d.

--- ./src/spectro_source.cc.orig	2022-08-11 14:19:16.000000000 +0000
+++ ./src/spectro_source.cc
@@ -294,12 +294,12 @@ spectrogram_source::list_value_for_overl
              sizeof(buf),
              ANSI_ROLE("  ") " 1-%'d " ANSI_ROLE("  ") " %'d-%'d " ANSI_ROLE(
                  "  ") " %'d+",
-             role_t::VCR_LOW_THRESHOLD,
+             (int)role_t::VCR_LOW_THRESHOLD,
              st.st_green_threshold - 1,
-             role_t::VCR_MED_THRESHOLD,
+             (int)role_t::VCR_MED_THRESHOLD,
              st.st_green_threshold,
              st.st_yellow_threshold - 1,
-             role_t::VCR_HIGH_THRESHOLD,
+             (int)role_t::VCR_HIGH_THRESHOLD,
              st.st_yellow_threshold);
     auto buflen = strlen(buf);
     if (line.length() + buflen + 20 < width) {
