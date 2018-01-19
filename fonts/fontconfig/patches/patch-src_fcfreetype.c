$NetBSD: patch-src_fcfreetype.c,v 1.1.2.2 2018/01/19 20:25:02 spz Exp $

Workaround for in-tree freetype2 headers from netbsd-6.

--- src/fcfreetype.c.orig	2017-09-21 07:53:35.000000000 +0000
+++ src/fcfreetype.c
@@ -1267,6 +1267,9 @@ FcFreeTypeQueryFace (const FT_Face  face
 	}
     }
 
+#if !defined(FT_SFNT_OS2) && !defined(ft_sfnt_os2)
+# define FT_SFNT_OS2 ft_sfnt_os2
+#endif
     /*
      * Get the OS/2 table
      */
