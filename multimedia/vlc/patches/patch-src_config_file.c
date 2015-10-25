$NetBSD: patch-src_config_file.c,v 1.3 2015/10/25 11:00:18 wiz Exp $

Rename strtoi to vlc_strtoi to avoid conflict with NetBSD built-in
function strtoi.

--- src/config/file.c.orig	2014-08-14 07:20:04.000000000 +0000
+++ src/config/file.c
@@ -138,7 +138,7 @@ static FILE *config_OpenConfigFile( vlc_
 }
 
 
-static int64_t strtoi (const char *str)
+static int64_t vlc_strtoi (const char *str)
 {
     char *end;
     long long l;
@@ -223,7 +223,7 @@ int config_LoadConfigFile( vlc_object_t 
                 int64_t l;
 
                 errno = 0;
-                l = strtoi (psz_option_value);
+                l = vlc_strtoi (psz_option_value);
                 if ((l > item->max.i) || (l < item->min.i))
                     errno = ERANGE;
                 if (errno)
