$NetBSD: patch-glib_gmain.c,v 1.1 2015/01/25 06:54:28 pho Exp $

Imported patch from the upstream Bugzilla:

  Bug 728123 - glib2 @2.40.0 issues a "Got weird mach timebase info" error (Macports, PPC)
  https://bugzilla.gnome.org/show_bug.cgi?id=728123

Tested on powerpc-apple-darwin9.

--- glib/gmain.c.orig	2014-11-09 21:54:26.000000000 +0000
+++ glib/gmain.c
@@ -2694,47 +2694,31 @@ g_get_monotonic_time (void)
 gint64
 g_get_monotonic_time (void)
 {
-  static mach_timebase_info_data_t timebase_info;
+  mach_timebase_info_data_t timebase_info;
+  guint64 val;
 
-  if (timebase_info.denom == 0)
-    {
-      /* This is a fraction that we must use to scale
-       * mach_absolute_time() by in order to reach nanoseconds.
-       *
-       * We've only ever observed this to be 1/1, but maybe it could be
-       * 1000/1 if mach time is microseconds already, or 1/1000 if
-       * picoseconds.  Try to deal nicely with that.
-       */
-      mach_timebase_info (&timebase_info);
-
-      /* We actually want microseconds... */
-      if (timebase_info.numer % 1000 == 0)
-        timebase_info.numer /= 1000;
-      else
-        timebase_info.denom *= 1000;
-
-      /* We want to make the numer 1 to avoid having to multiply... */
-      if (timebase_info.denom % timebase_info.numer == 0)
-        {
-          timebase_info.denom /= timebase_info.numer;
-          timebase_info.numer = 1;
-        }
-      else
-        {
-          /* We could just multiply by timebase_info.numer below, but why
-           * bother for a case that may never actually exist...
-           *
-           * Plus -- performing the multiplication would risk integer
-           * overflow.  If we ever actually end up in this situation, we
-           * should more carefully evaluate the correct course of action.
-           */
-          mach_timebase_info (&timebase_info); /* Get a fresh copy for a better message */
-          g_error ("Got weird mach timebase info of %d/%d.  Please file a bug against GLib.",
-                   timebase_info.numer, timebase_info.denom);
-        }
+  /* we get nanoseconds from mach_absolute_time() using timebase_info */
+  mach_timebase_info (&timebase_info);
+  val = mach_absolute_time();
+
+  if (timebase_info.numer != timebase_info.denom)
+    {
+      guint64 t_high, t_low;
+      guint64 result_high, result_low;
+
+      /* 64 bit x 32 bit / 32 bit with 96-bit intermediate 
+       * algorithm lifted from qemu */
+      t_low = (val & 0xffffffffLL) * (guint64)timebase_info.numer;
+      t_high = (val >> 32) * (guint64)timebase_info.numer;
+      t_high += (t_low >> 32);
+      result_high = t_high / (guint64)timebase_info.denom;
+      result_low = (((t_high % (guint64)timebase_info.denom) << 32) +
+                   (t_low & 0xffffffff)) / (guint64)timebase_info.denom;
+      val = ((result_high << 32) | result_low);
     }
 
-  return mach_absolute_time () / timebase_info.denom;
+  /* nanoseconds to microseconds */
+  return val / 1000;
 }
 #else
 gint64
