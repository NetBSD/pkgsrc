$NetBSD: patch-jsdate.cpp,v 1.1 2020/04/05 06:10:28 wiz Exp $

Always use the equivalent year to determine the time zone offset and name

Reviewed-by: Jeff Walden
Bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1415202
Bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1479687
Origin: upstream
Applied-upstream: 62, commit:https://hg.mozilla.org/mozilla-central/rev/ce9f1466ec78

--- jsdate.cpp.orig	2019-07-01 09:07:41.000000000 +0000
+++ jsdate.cpp
@@ -2353,12 +2353,16 @@ static PRMJTime ToPRMJTime(double localT
 static size_t FormatTime(char* buf, int buflen, const char* fmt, double utcTime,
                          double localTime) {
   PRMJTime prtm = ToPRMJTime(localTime, utcTime);
-  int eqivalentYear = IsRepresentableAsTime32(utcTime)
-                          ? prtm.tm_year
-                          : EquivalentYearForDST(prtm.tm_year);
+
+  // If an equivalent year was used to compute the date/time components, use
+  // the same equivalent year to determine the time zone name and offset in
+  // PRMJ_FormatTime(...).
+  int timeZoneYear = IsRepresentableAsTime32(utcTime)
+                         ? prtm.tm_year
+                         : EquivalentYearForDST(prtm.tm_year);
   int offsetInSeconds = (int)floor((localTime - utcTime) / msPerSecond);
 
-  return PRMJ_FormatTime(buf, buflen, fmt, &prtm, eqivalentYear,
+  return PRMJ_FormatTime(buf, buflen, fmt, &prtm, timeZoneYear,
                          offsetInSeconds);
 }
 
