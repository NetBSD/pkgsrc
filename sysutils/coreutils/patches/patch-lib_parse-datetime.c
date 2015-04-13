$NetBSD: patch-lib_parse-datetime.c,v 1.1 2015/04/13 12:05:08 tnn Exp $

Fix CVE-2014-9471 TZ parsing bug.
Via https://debbugs.gnu.org/cgi/bugreport.cgi?bug=16872

Note that we patch the generated parser instead of the
bison grammar to avoid adding bison dependency here.

--- lib/parse-datetime.c.orig	2013-12-09 14:43:39.000000000 +0000
+++ lib/parse-datetime.c
@@ -3207,8 +3207,6 @@ parse_datetime (struct timespec *result,
             char tz1buf[TZBUFSIZE];
             bool large_tz = TZBUFSIZE < tzsize;
             bool setenv_ok;
-            /* Free tz0, in case this is the 2nd or subsequent time through. */
-            free (tz0);
             tz0 = get_tz (tz0buf);
             z = tz1 = large_tz ? xmalloc (tzsize) : tz1buf;
             for (s = tzbase; *s != '"'; s++)
@@ -3220,7 +3218,12 @@ parse_datetime (struct timespec *result,
             if (!setenv_ok)
               goto fail;
             tz_was_altered = true;
+
             p = s + 1;
+            while (c = *p, c_isspace (c))
+              p++;
+
+            break;
           }
     }
 
