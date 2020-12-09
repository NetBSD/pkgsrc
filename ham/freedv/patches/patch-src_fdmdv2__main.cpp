$NetBSD: patch-src_fdmdv2__main.cpp,v 1.1 2020/12/09 10:38:04 nia Exp $

src/fdmdv2_main.cpp:1026:37: error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?
 1026 |     if (!(isnan(g_stats.snr_est) || isinf(g_stats.snr_est))) {
      |                                     ^~~~~
      |                                     std::isinf

--- src/fdmdv2_main.cpp.orig	2020-07-18 23:16:05.000000000 +0000
+++ src/fdmdv2_main.cpp
@@ -1023,7 +1023,7 @@ void MainFrame::OnTimer(wxTimerEvent &ev
 
     float snr_limited;
     // some APIs pass us invalid values, so lets trap it rather than bombing
-    if (!(isnan(g_stats.snr_est) || isinf(g_stats.snr_est))) {
+    if (!(std::isnan(g_stats.snr_est) || std::isinf(g_stats.snr_est))) {
         if (g_mode == -1) {
             // no averaging of SNR for horus telemetry, just report latest and greatest 
             g_snr = g_stats.snr_est;
