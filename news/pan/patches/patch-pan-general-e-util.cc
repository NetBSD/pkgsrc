$NetBSD: patch-pan-general-e-util.cc,v 1.1 2018/11/18 14:31:56 rhialto Exp $

Replace UTF-8 colons by real ones, so it works in more locales.

diff --git a/pan/general/e-util.cc b/pan/general/e-util.cc
index af5ccd0..efb7932 100644
--- pan/general/e-util.cc
+++ pan/general/e-util.cc
@@ -208,10 +208,10 @@ EvolutionDateMaker :: set_current_time (time_t now)
 EvolutionDateMaker :: EvolutionDateMaker (time_t now)
 {
   // build the locale strings
-  locale_recent = g_locale_from_utf8 (_("%l∶%M %p"), -1, NULL, NULL, NULL);
-  locale_today = g_locale_from_utf8 (_("Today %l∶%M %p"), -1, NULL, NULL, NULL);
-  locale_this_week = g_locale_from_utf8 (_("%a %l∶%M %p"), -1, NULL, NULL, NULL);
-  locale_this_year = g_locale_from_utf8 (_("%b %d %l∶%M %p"), -1, NULL, NULL, NULL);
+  locale_recent = g_locale_from_utf8 (_("%l:%M %p"), -1, NULL, NULL, NULL);
+  locale_today = g_locale_from_utf8 (_("Today %l:%M %p"), -1, NULL, NULL, NULL);
+  locale_this_week = g_locale_from_utf8 (_("%a %l:%M %p"), -1, NULL, NULL, NULL);
+  locale_this_year = g_locale_from_utf8 (_("%b %d %l:%M %p"), -1, NULL, NULL, NULL);
   locale_old = g_locale_from_utf8 (_("%b %d %Y"), -1, NULL, NULL, NULL);
 
   // set the current time
