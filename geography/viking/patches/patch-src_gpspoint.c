$NetBSD: patch-src_gpspoint.c,v 1.1 2019/01/22 15:28:45 gdt Exp $

Work around a bug in NetBSD.  See PR standards/40695.  Bug is fixed in
-current but not -5; revisit if the workaround causes problems.
While 5 is very old, keep the patch because somebody might be using it
and the pach is not problematic.
(Not filed upstream because this is a NetBSD bug.)

--- src/gpspoint.c.orig	2018-12-23 10:48:06.000000000 +0000
+++ src/gpspoint.c
@@ -94,8 +94,25 @@ static gdouble line_altitude = VIK_DEFAU
 static gboolean line_visible = TRUE;
 
 static gboolean line_extended = FALSE;
+#if defined(__NetBSD__)
+#if __GNUC_PREREQ__(3,3)
+/*
+ * Work around a bug in NetBSD.  See PR standards/40695.  Bug is fixed
+ * in -current but not -5; revisit if the workaround causes problems.
+ */
+static gdouble line_speed = __builtin_nanf("");
+static gdouble line_course = __builtin_nanf("");
+#else /* _GNUC_PREREQ__(3,3) */
+/*
+ * gcc too old for workaround; defer fix to someone else.
+ */
+static gdouble line_speed = NAN;
+static gdouble line_course = NAN;
+#endif /* _GNUC_PREREQ__(3,3) */
+#else /* NetBSD */
 static gdouble line_speed = NAN;
 static gdouble line_course = NAN;
+#endif /* NetBSD */
 static gint line_sat = 0;
 static gint line_fix = 0;
 static gdouble line_hdop = VIK_DEFAULT_DOP;
