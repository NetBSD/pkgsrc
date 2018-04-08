$NetBSD: patch-src_editfns.c,v 1.1 2018/04/08 03:03:48 dholland Exp $

Fixes for tzalloc issues on -6 from uwe@ and Paul Eggert
https://debbugs.gnu.org/cgi/bugreport.cgi?bug=30738

(Note: it is probably not only old netbsd that has old tzcode that
wants this workaround, so we might want to broaden the tests.)

--- src/editfns.c.orig	2017-04-14 15:02:47.000000000 +0000
+++ src/editfns.c
@@ -48,6 +48,16 @@ along with GNU Emacs.  If not, see <http
 #include <float.h>
 #include <limits.h>
 
+#ifdef HAVE_TIMEZONE_T
+# include <sys/param.h>
+# if defined __NetBSD_Version__ && __NetBSD_Version__ < 700000000
+#  define HAVE_TZALLOC_BUG true
+# endif
+#endif
+#ifndef HAVE_TZALLOC_BUG
+# define HAVE_TZALLOC_BUG false
+#endif
+
 #include <intprops.h>
 #include <strftime.h>
 #include <verify.h>
@@ -80,10 +90,8 @@ static Lisp_Object styled_format (ptrdif
 
 enum { tzeqlen = sizeof "TZ=" - 1 };
 
-/* Time zones equivalent to current local time, to wall clock time,
-   and to UTC, respectively.  */
+/* Time zones equivalent to current local time and to UTC, respectively.  */
 static timezone_t local_tz;
-static timezone_t wall_clock_tz;
 static timezone_t const utc_tz = 0;
 
 /* A valid but unlikely setting for the TZ environment variable.
@@ -120,14 +128,10 @@ emacs_mktime_z (timezone_t tz, struct tm
   return t;
 }
 
-/* Allocate a timezone, signaling on failure.  */
-static timezone_t
-xtzalloc (char const *name)
+static _Noreturn void
+invalid_time_zone_specification (Lisp_Object zone)
 {
-  timezone_t tz = tzalloc (name);
-  if (!tz)
-    memory_full (SIZE_MAX);
-  return tz;
+  xsignal2 (Qerror, build_string ("Invalid time zone specification"), zone);
 }
 
 /* Free a timezone, except do not free the time zone for local time.
@@ -153,7 +157,7 @@ tzlookup (Lisp_Object zone, bool settz)
 
   if (NILP (zone))
     return local_tz;
-  else if (EQ (zone, Qt))
+  else if (EQ (zone, Qt) || EQ (zone, make_number (0)))
     {
       zone_string = "UTC0";
       new_tz = utc_tz;
@@ -172,9 +176,25 @@ tzlookup (Lisp_Object zone, bool settz)
 	  zone_string = tzbuf;
 	}
       else
-	xsignal2 (Qerror, build_string ("Invalid time zone specification"),
-		  zone);
-      new_tz = xtzalloc (zone_string);
+	invalid_time_zone_specification (zone);
+
+      new_tz = tzalloc (zone_string);
+
+      if (HAVE_TZALLOC_BUG && !new_tz && errno != ENOMEM && INTEGERP (zone)
+	  && XINT (zone) % (60 * 60) == 0)
+	{
+	  /* tzalloc mishandles POSIX strings; fall back on tzdb if
+	     possible (Bug#30738).  */
+	  sprintf (tzbuf, "Etc/GMT%+"pI"d", - (XINT (zone) / (60 * 60)));
+	  new_tz = tzalloc (zone_string);
+	}
+
+      if (!new_tz)
+	{
+	  if (errno == ENOMEM)
+	    memory_full (SIZE_MAX);
+	  invalid_time_zone_specification (zone);
+	}
     }
 
   if (settz)
@@ -232,7 +252,6 @@ init_editfns (bool dumping)
 
   /* Set the time zone rule now, so that the call to putenv is done
      before multiple threads are active.  */
-  wall_clock_tz = xtzalloc (0);
   tzlookup (tz ? build_string (tz) : Qwall, true);
 
   pw = getpwuid (getuid ());
