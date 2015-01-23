$NetBSD: patch-src_config_file.c,v 1.1 2015/01/23 16:01:40 wiz Exp $

Rename strtoi to vlc_strtoi to avoid conflict with NetBSD built-in
function strtoi.

--- src/config/file.c.orig	2013-06-24 18:00:39.000000000 +0000
+++ src/config/file.c
@@ -140,7 +140,7 @@ static FILE *config_OpenConfigFile( vlc_
 }
 
 
-static int64_t strtoi (const char *str)
+static int64_t vlc_strtoi (const char *str)
 {
     char *end;
     long long l;
@@ -225,7 +225,7 @@ int config_LoadConfigFile( vlc_object_t 
                 int64_t l;
 
                 errno = 0;
-                l = strtoi (psz_option_value);
+                l = vlc_strtoi (psz_option_value);
                 if ((l > item->max.i) || (l < item->min.i))
                     errno = ERANGE;
                 if (errno)
