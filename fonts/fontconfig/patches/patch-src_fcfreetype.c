$NetBSD: patch-src_fcfreetype.c,v 1.2 2018/03/11 17:54:03 wiz Exp $

Workaround for in-tree freetype2 headers from netbsd-6.

--- src/fcfreetype.c.orig	2018-03-02 04:27:09.000000000 +0000
+++ src/fcfreetype.c
@@ -1338,6 +1338,9 @@ FcFreeTypeQueryFaceInternal (const FT_Fa
     if (!FcPatternAddBool (pat, FC_VARIABLE, variable))
 	goto bail1;
 
+#if !defined(FT_SFNT_OS2) && !defined(ft_sfnt_os2)
+# define FT_SFNT_OS2 ft_sfnt_os2
+#endif
     /*
      * Get the OS/2 table
      */
