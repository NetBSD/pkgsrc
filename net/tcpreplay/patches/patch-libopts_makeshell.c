$NetBSD: patch-libopts_makeshell.c,v 1.1 2017/12/04 09:32:01 he Exp $

Ensure args to toxxxx() are within allowed value range.

--- ./libopts/makeshell.c.orig	2017-04-27 00:56:25.000000000 +0000
+++ ./libopts/makeshell.c
@@ -396,7 +396,7 @@ emit_usage(tOptions * opts)
 
         /* Copy the program name into the time/name buffer */
         for (;;) {
-            if ((*pzPN++ = (char)tolower(*pz++)) == NUL)
+            if ((*pzPN++ = (char)tolower((unsigned char)*pz++)) == NUL)
                 break;
         }
 
@@ -653,7 +653,7 @@ emit_match_expr(char const * name, tOptD
              *  They must not be the same.  They cannot be, because it would
              *  not compile correctly if they were.
              */
-            while (toupper(od->pz_Name[match_ct]) == toupper(name[match_ct]))
+            while (toupper((unsigned char)od->pz_Name[match_ct]) == toupper((unsigned char)name[match_ct]))
                 match_ct++;
 
             if (match_ct > min_match_ct)
@@ -666,8 +666,8 @@ emit_match_expr(char const * name, tOptD
                 continue;
 
             match_ct = 0;
-            while (  toupper(od->pz_DisableName[match_ct])
-                  == toupper(name[match_ct]))
+            while (  toupper((unsigned char)od->pz_DisableName[match_ct])
+                  == toupper((unsigned char)name[match_ct]))
                 match_ct++;
             if (match_ct > min_match_ct)
                 min_match_ct = match_ct;
@@ -905,7 +905,7 @@ genshelloptUsage(tOptions * opts, int ex
         AGDUPSTR(pz, optionParseShellOptions->pzPROGNAME, "prog name");
         *pp = pz;
         while (*pz != NUL) {
-            *pz = (char)tolower(*pz);
+            *pz = (char)tolower((unsigned char)*pz);
             pz++;
         }
     }
