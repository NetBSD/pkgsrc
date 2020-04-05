$NetBSD: patch-vm_Time.cpp,v 1.1 2020/04/05 06:10:28 wiz Exp $

Always use the equivalent year to determine the time zone offset and name

Reviewed-by: Jeff Walden
Bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1415202
Bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1479687
Origin: upstream
Applied-upstream: 62, commit:https://hg.mozilla.org/mozilla-central/rev/ce9f1466ec78

--- vm/Time.cpp.orig	2019-07-01 09:07:44.000000000 +0000
+++ vm/Time.cpp
@@ -247,7 +247,7 @@ static void PRMJ_InvalidParameterHandler
 
 /* Format a time value into a buffer. Same semantics as strftime() */
 size_t PRMJ_FormatTime(char* buf, int buflen, const char* fmt,
-                       const PRMJTime* prtm, int equivalentYear,
+                       const PRMJTime* prtm, int timeZoneYear,
                        int offsetInSeconds) {
   size_t result = 0;
 #if defined(XP_UNIX) || defined(XP_WIN)
@@ -280,7 +280,8 @@ size_t PRMJ_FormatTime(char* buf, int bu
      * Fill out |td| to the time represented by |prtm|, leaving the
      * timezone fields zeroed out. localtime_r will then fill in the
      * timezone fields for that local time according to the system's
-     * timezone parameters.
+     * timezone parameters. Use |timeZoneYear| for the year to ensure the time
+     * zone name matches the time zone offset used by the caller.
      */
     struct tm td;
     memset(&td, 0, sizeof(td));
@@ -290,19 +291,12 @@ size_t PRMJ_FormatTime(char* buf, int bu
     td.tm_mday = prtm->tm_mday;
     td.tm_mon = prtm->tm_mon;
     td.tm_wday = prtm->tm_wday;
-    td.tm_year = prtm->tm_year - 1900;
+    td.tm_year = timeZoneYear - 1900;
     td.tm_yday = prtm->tm_yday;
     td.tm_isdst = prtm->tm_isdst;
 
     time_t t = mktime(&td);
 
-    // If |prtm| cannot be represented in |time_t| the year is probably
-    // out of range, try again with the DST equivalent year.
-    if (t == static_cast<time_t>(-1)) {
-      td.tm_year = equivalentYear - 1900;
-      t = mktime(&td);
-    }
-
     // If either mktime or localtime_r failed, fill in the fallback time
     // zone offset |offsetInSeconds| and set the time zone identifier to
     // the empty string.
