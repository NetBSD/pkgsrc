$NetBSD: patch-argp-fmtstream.c,v 1.3 2026/06/23 09:52:25 wiz Exp $

Fix ctype(3) usage.

--- argp-fmtstream.c.orig	2022-05-03 07:41:05.000000000 +0000
+++ argp-fmtstream.c
@@ -225,7 +225,7 @@ __argp_fmtstream_update(argp_fmtstream_t fs)
             int i;
 
             p = buf + (r + 1 - fs->point_col);
-            while (p >= buf && !isblank(*p))
+            while (p >= buf && !isblank((unsigned char)*p))
                 --p;
             nextline = p + 1; /* This will begin the next line.  */
 
@@ -235,7 +235,7 @@ __argp_fmtstream_update(argp_fmtstream_t fs)
                 if (p >= buf)
                     do
                         --p;
-                    while (p >= buf && isblank(*p));
+                    while (p >= buf && isblank((unsigned char)*p));
                 nl = p + 1; /* The newline will replace the first blank. */
             }
             else
@@ -246,7 +246,7 @@ __argp_fmtstream_update(argp_fmtstream_t fs)
                 /* Find the end of the long word.  */
                 do
                     ++p;
-                while (p < nl && !isblank(*p));
+                while (p < nl && !isblank((unsigned char)*p));
                 if (p == nl)
                 {
                     /* It already ends a line.  No fussing required.  */
@@ -259,7 +259,7 @@ __argp_fmtstream_update(argp_fmtstream_t fs)
                 /* Swallow separating blanks.  */
                 do
                     ++p;
-                while (isblank(*p));
+                while (isblank((unsigned char)*p));
                 /* The next line will start here.  */
                 nextline = p;
             }
