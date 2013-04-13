$NetBSD: patch-glib_glib_gatomic.c,v 1.1 2013/04/13 11:10:04 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gatomic.c.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/gatomic.c
@@ -464,7 +464,7 @@ gsize
   return g_atomic_pointer_xor ((volatile gpointer *) atomic, val);
 }
 
-#elif defined (G_PLATFORM_WIN32)
+#elif defined (G_OS_WIN32)
 
 #include <windows.h>
 #if !defined(_M_AMD64) && !defined (_M_IA64) && !defined(_M_X64)
