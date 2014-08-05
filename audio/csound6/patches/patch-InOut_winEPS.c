$NetBSD: patch-InOut_winEPS.c,v 1.2 2014/08/05 05:12:38 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- InOut/winEPS.c.orig	2005-12-29 05:49:04.000000000 -0800
+++ InOut/winEPS.c
@@ -146,7 +146,7 @@ void PS_MakeGraph(CSOUND *csound, WINDAT
      *  Get the current time and date
      */
     lt = time(NULL);
-#ifndef LINUX
+#if !defined(LINUX) && !defined(__NetBSD__) && !defined(__DragonFly__)
     {
       struct tm *date_ptr;
       char      *date;
