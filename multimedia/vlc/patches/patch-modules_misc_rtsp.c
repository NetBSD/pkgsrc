$NetBSD: patch-modules_misc_rtsp.c,v 1.1 2013/09/08 16:28:27 joerg Exp $

--- modules/misc/rtsp.c.orig	2013-05-15 20:28:04.000000000 +0000
+++ modules/misc/rtsp.c
@@ -952,22 +952,26 @@ static void RtspClientDel( vod_media_t *
 
 static float ParseNPT (const char *str)
 {
+#ifndef LC_C_LOCALE
      locale_t loc = newlocale (LC_NUMERIC_MASK, "C", NULL);
      locale_t oldloc = uselocale (loc);
+#endif
      unsigned hour, min;
      float sec;
 
-     if (sscanf (str, "%u:%u:%f", &hour, &min, &sec) == 3)
+     if (sscanf_l (str, LC_C_LOCALE, "%u:%u:%f", &hour, &min, &sec) == 3)
          sec += ((hour * 60) + min) * 60;
      else
-     if (sscanf (str, "%f", &sec) != 1)
+     if (sscanf_l (str, LC_C_LOCALE, "%f", &sec) != 1)
          sec = 0.;
 
+#ifndef LC_C_LOCALE
      if (loc != (locale_t)0)
      {
          uselocale (oldloc);
          freelocale (loc);
      }
+#endif
      return sec;
 }
 
