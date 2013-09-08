$NetBSD: patch-src_config_file.c,v 1.1 2013/09/08 16:28:27 joerg Exp $

--- src/config/file.c.orig	2013-05-15 20:27:58.000000000 +0000
+++ src/config/file.c
@@ -187,8 +187,10 @@ int config_LoadConfigFile( vlc_object_t 
     section[0] = '\0';
 
     /* Ensure consistent number formatting... */
+#ifndef LC_C_LOCALE
     locale_t loc = newlocale (LC_NUMERIC_MASK, "C", NULL);
     locale_t baseloc = uselocale (loc);
+#endif
 
     vlc_rwlock_wrlock (&config_lock);
     while (fgets (line, 1024, file) != NULL)
@@ -282,7 +284,7 @@ int config_LoadConfigFile( vlc_object_t 
                 case CONFIG_ITEM_FLOAT:
                     if( !*psz_option_value )
                         break;                    /* ignore empty option */
-                    p_item->value.f = (float)atof (psz_option_value);
+                    p_item->value.f = strtof_l(psz_option_value, NULL, LC_C_LOCALE);
                     p_item->saved.f = p_item->value.f;
                     break;
 
@@ -315,11 +317,13 @@ int config_LoadConfigFile( vlc_object_t 
     fclose (file);
 
     module_list_free (list);
+#ifndef LC_C_LOCALE
     if (loc != (locale_t)0)
     {
         uselocale (baseloc);
         freelocale (loc);
     }
+#endif
     return 0;
 }
 
@@ -570,8 +574,10 @@ static int SaveConfigFile( vlc_object_t 
         "\n" );
 
     /* Ensure consistent number formatting... */
+#ifndef LC_C_LOCALE
     locale_t loc = newlocale (LC_NUMERIC_MASK, "C", NULL);
     locale_t baseloc = uselocale (loc);
+#endif
 
     /* We would take the config lock here. But this would cause a lock
      * inversion with the serializer above and config_AutoSaveConfigFile().
@@ -683,11 +689,13 @@ static int SaveConfigFile( vlc_object_t 
     vlc_rwlock_unlock (&config_lock);
 
     module_list_free (list);
+#ifndef LC_C_LOCALE
     if (loc != (locale_t)0)
     {
         uselocale (baseloc);
         freelocale (loc);
     }
+#endif
 
     /*
      * Restore old settings from the config in file
