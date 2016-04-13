$NetBSD: patch-src_unexfreebsd.c,v 1.2 2016/04/13 13:52:27 hauke Exp $

Build on NetBSD/arm*

--- src/unexfreebsd.c.orig	2015-01-29 15:04:29.000000000 +0000
+++ src/unexfreebsd.c
@@ -289,7 +289,7 @@ copy_relocation_site (struct relocation_
   /* We can get relocation sites in the bss region, for objects whose
      contents are copied from a shared library.  We don't need or want
      to restore these at present. */
-#ifndef sparc
+#if !defined(sparc) && !defined(__arm__)
   if (ri->r_copy)
     return;
 #else
