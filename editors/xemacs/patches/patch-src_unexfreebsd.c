$NetBSD: patch-src_unexfreebsd.c,v 1.1 2015/02/04 09:19:20 hauke Exp $

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
