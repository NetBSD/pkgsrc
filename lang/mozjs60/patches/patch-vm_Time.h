$NetBSD: patch-vm_Time.h,v 1.1 2020/04/05 06:10:28 wiz Exp $

Always use the equivalent year to determine the time zone offset and name

Reviewed-by: Jeff Walden
Bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1415202
Bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1479687
Origin: upstream
Applied-upstream: 62, commit:https://hg.mozilla.org/mozilla-central/rev/ce9f1466ec78

--- vm/Time.h.orig	2019-07-01 09:07:43.000000000 +0000
+++ vm/Time.h
@@ -49,7 +49,7 @@ inline void PRMJ_NowShutdown() {}
 
 /* Format a time value into a buffer. Same semantics as strftime() */
 extern size_t PRMJ_FormatTime(char* buf, int buflen, const char* fmt,
-                              const PRMJTime* tm, int equivalentYear,
+                              const PRMJTime* tm, int timeZoneYear,
                               int offsetInSeconds);
 
 /**
