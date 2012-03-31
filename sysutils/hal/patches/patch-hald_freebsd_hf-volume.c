$NetBSD: patch-hald_freebsd_hf-volume.c,v 1.1 2012/03/31 16:06:56 ryoon Exp $

* From FreeBSD ports repository to fix build on FreeBSD 9.0 RELEASE.

--- hald/freebsd/hf-volume.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/hf-volume.c
@@ -86,9 +86,12 @@ hf_volume_resolve_fuse (const char *spec
         {
           if (strcmp(fields[0], special) == 0)
 	    {
+	      char *ret;
+
+	      ret = g_strdup(fields[1]);
 	      g_strfreev(fields);
 	      g_strfreev(lines);
-	      return g_strdup(fields[1]);
+	      return ret;
 	    }
 	}
       g_strfreev(fields);
