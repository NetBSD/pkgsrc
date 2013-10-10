$NetBSD: patch-record.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- record.c.orig	2013-10-09 23:15:59.000000000 +0000
+++ record.c
@@ -337,11 +337,12 @@ void recsavedrf(void)
   char nambuf[80],init[4];
   if (!drfvalid)
     return;
-  if (gotname)
+  if (gotname) {
     if ((recf=fopen(rname,"wt"))==NULL)
       gotname=FALSE;
     else
       gotfile=TRUE;
+  }
   if (!gotname) {
     if (nplayers==2)
       recf=fopen(DEFAULTSN,"wt"); /* Should get a name, really */
