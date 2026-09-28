$NetBSD: patch-DBI.xs,v 1.2 2026/09/28 07:20:14 wiz Exp $

https://github.com/perl5-dbi/dbi/commit/ff4f1baf0389dfa5e7282e1d8d7423c1b5e06b76

--- DBI.xs.orig	2026-09-10 08:59:53.000000000 +0000
+++ DBI.xs
@@ -1925,6 +1925,8 @@ sql_type_cast_svpv(pTHX_ SV *sv, int sql_type, U32 fla
     int cast_ok = 0;
     int grok_flags;
     UV uv;
+    STRLEN len;
+    char *p;
 
     /* do nothing for undef (NULL) or non-string values */
     if (!sv || !SvOK(sv))
@@ -1957,8 +1959,7 @@ sql_type_cast_svpv(pTHX_ SV *sv, int sql_type, U32 fla
     /* else no error and sv is untouched */
     case SQL_NUMERIC:
         /* based on the code in perl's toke.c */
-        STRLEN len;
-        char *p = SvPV(sv, len); /* force stringify, handle magic */
+        p = SvPV(sv, len); /* force stringify, handle magic */
         uv = 0;
         grok_flags = grok_number(p, len, &uv);
         cast_ok = 1;
