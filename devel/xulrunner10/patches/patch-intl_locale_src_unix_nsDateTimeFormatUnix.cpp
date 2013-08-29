$NetBSD: patch-intl_locale_src_unix_nsDateTimeFormatUnix.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- intl/locale/src/unix/nsDateTimeFormatUnix.cpp.orig	2013-07-14 14:38:11.000000000 +0000
+++ intl/locale/src/unix/nsDateTimeFormatUnix.cpp
@@ -133,7 +133,7 @@ void nsDateTimeFormatUnix::LocalePreferr
   struct tm *tmc;
   int i;
 
-  tt = time((time_t)NULL);
+  tt = time((time_t *)NULL);
   tmc = localtime(&tt);
 
   tmc->tm_hour=22;    // put the test sample hour to 22:00 which is 10PM
