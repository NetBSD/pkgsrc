$NetBSD: patch-gio_gresource-tool.c,v 1.1 2012/07/12 14:43:26 jperkin Exp $

--- gio/gresource-tool.c.orig	Thu Jul 12 09:13:01 2012
+++ gio/gresource-tool.c	Thu Jul 12 09:13:06 2012
@@ -31,6 +31,11 @@
 #include <locale.h>
 
 #ifdef HAVE_LIBELF
+/* Solaris native libelf does not support largefile in 32-bit mode */
+#  if defined(__sun) && defined(__i386)
+#    undef  _FILE_OFFSET_BITS
+#    define _FILE_OFFSET_BITS   32
+#  endif
 #include <libelf.h>
 #include <gelf.h>
 #include <sys/mman.h>
