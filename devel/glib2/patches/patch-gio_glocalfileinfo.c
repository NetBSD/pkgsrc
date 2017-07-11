$NetBSD: patch-gio_glocalfileinfo.c,v 1.1 2017/07/11 11:52:42 jperkin Exp $

Re-enable gdesktopappinfo on Darwin.

--- gio/glocalfileinfo.c.orig	2017-06-22 12:52:49.000000000 +0000
+++ gio/glocalfileinfo.c
@@ -1259,7 +1259,7 @@ get_content_type (const char          *b
 
       content_type = g_content_type_guess (basename, NULL, 0, &result_uncertain);
       
-#if !defined(G_OS_WIN32) && !defined(HAVE_COCOA)
+#if !defined(G_OS_WIN32)
       if (!fast && result_uncertain && path != NULL)
 	{
 	  guchar sniff_buffer[4096];
