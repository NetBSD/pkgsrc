$NetBSD: patch-src_config_file.c,v 1.1 2015/01/23 16:15:42 wiz Exp $

Fix conflict with NetBSD's strtoi function.

--- src/config/file.c.orig	2011-12-08 18:00:28.000000000 +0000
+++ src/config/file.c
@@ -139,7 +139,7 @@ static FILE *config_OpenConfigFile( vlc_
 }
 
 
-static int64_t strtoi (const char *str)
+static int64_t vlc_strtoi (const char *str)
 {
     char *end;
     long long l;
@@ -224,7 +224,7 @@ int config_LoadConfigFile( vlc_object_t 
                 int64_t l;
 
                 errno = 0;
-                l = strtoi (psz_option_value);
+                l = vlc_strtoi (psz_option_value);
                 if ((l > item->max.i) || (l < item->min.i))
                     errno = ERANGE;
                 if (errno)
