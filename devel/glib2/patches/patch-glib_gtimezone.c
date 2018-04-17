$NetBSD: patch-glib_gtimezone.c,v 1.3 2018/04/17 08:03:38 wiz Exp $

Bug 730332 - glib uses wrong timezone transition with zoneinfo 2014c
https://bugzilla.gnome.org/show_bug.cgi?id=730332

Patch from John Ralls.

--- glib/gtimezone.c.orig	2013-11-07 15:29:13.000000000 +0000
+++ glib/gtimezone.c
@@ -1558,7 +1558,11 @@ interval_end (GTimeZone *tz,
               guint      interval)
 {
   if (tz->transitions && interval < tz->transitions->len)
+  {
+    if ((TRANSITION(interval)).time == G_MININT64)
+      return G_MININT64;
     return (TRANSITION(interval)).time - 1;
+  }
   return G_MAXINT64;
 }
 
