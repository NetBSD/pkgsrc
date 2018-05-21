$NetBSD: patch-gio_glocalfileinfo.c,v 1.3 2018/05/21 08:39:38 jperkin Exp $

Re-enable gdesktopappinfo on Darwin.

--- gio/glocalfileinfo.c.orig	2018-01-08 21:34:19.000000000 +0000
+++ gio/glocalfileinfo.c
@@ -1290,7 +1290,7 @@ get_content_type (const char          *b
 
       content_type = g_content_type_guess (basename, NULL, 0, &result_uncertain);
       
-#if !defined(G_OS_WIN32) && !defined(HAVE_COCOA)
+#if !defined(G_OS_WIN32)
       if (!fast && result_uncertain && path != NULL)
 	{
 	  guchar sniff_buffer[4096];
