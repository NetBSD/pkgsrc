$NetBSD: patch-DBI.xs,v 1.1 2026/09/28 07:18:10 wiz Exp $

Variable definition only at block start.

--- DBI.xs.orig	2026-09-28 07:16:56.764598578 +0000
+++ DBI.xs
@@ -1925,6 +1925,7 @@ sql_type_cast_svpv(pTHX_ SV *sv, int sql_type, U32 fla
     int cast_ok = 0;
     int grok_flags;
     UV uv;
+    STRLEN len;
 
     /* do nothing for undef (NULL) or non-string values */
     if (!sv || !SvOK(sv))
@@ -1957,7 +1958,6 @@ sql_type_cast_svpv(pTHX_ SV *sv, int sql_type, U32 fla
     /* else no error and sv is untouched */
     case SQL_NUMERIC:
         /* based on the code in perl's toke.c */
-        STRLEN len;
         char *p = SvPV(sv, len); /* force stringify, handle magic */
         uv = 0;
         grok_flags = grok_number(p, len, &uv);
