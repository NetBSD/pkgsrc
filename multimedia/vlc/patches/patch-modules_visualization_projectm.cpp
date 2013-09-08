$NetBSD: patch-modules_visualization_projectm.cpp,v 1.1 2013/09/08 16:28:27 joerg Exp $

--- modules/visualization/projectm.cpp.orig	2013-05-15 20:28:01.000000000 +0000
+++ modules/visualization/projectm.cpp
@@ -344,8 +344,10 @@ static void *Thread( void *p_data )
         goto error;
     }
 
+#ifndef LC_C_LOCALE
     loc = newlocale (LC_NUMERIC_MASK, "C", NULL);
     oldloc = uselocale (loc);
+#endif
     /* Create the projectM object */
 #ifndef HAVE_PROJECTM2
     psz_config = var_InheritString( p_filter, "projectm-config" );
@@ -428,11 +430,13 @@ static void *Thread( void *p_data )
             delete p_projectm;
             vout_DeleteDisplay( p_sys->p_vd, NULL );
             vlc_object_release( p_sys->p_vout );
+#ifndef LC_C_LOCALE
             if (loc != (locale_t)0)
             {
                 uselocale (oldloc);
                 freelocale (loc);
             }
+#endif
             return NULL;
         }
         vlc_mutex_unlock( &p_sys->lock );
