$NetBSD: patch-src_base.h,v 1.1 2014/11/10 18:05:45 joerg Exp $

--- src/base.h.orig	2014-11-10 12:50:39.000000000 +0000
+++ src/base.h
@@ -753,8 +753,7 @@ int dorewrite (bool lockflag, int change
 int donerewrite (int changed, time_t newRCStime);
 void ORCSclose (void);
 void ORCSerror (void);
-void unexpected_EOF (void)
-  exiting;
+exiting void unexpected_EOF (void);
 void initdiffcmd (struct diffcmd *dc);
 int getdiffcmd (struct fro *finfile, bool delimiter,
                 FILE *foutfile, struct diffcmd *dc);
@@ -829,8 +828,7 @@ char const *date2str (char const date[da
                       char datebuf[datesize + zonelenmax]);
 
 /* rcsutil */
-void thank_you_and_goodnight (int const how)
-  exiting;
+exiting void thank_you_and_goodnight (int const how);
 /* These are for ‘thank_you_and_goodnight’.  */
 #define TYAG_ORCSERROR     (1 << 3)
 #define TYAG_DIRTMPUNLINK  (1 << 2)
