$NetBSD: patch-plugins_i2c-proc_i2c-proc-plugin.c,v 1.1 2020/08/22 00:46:49 gutteridge Exp $

Expect basic headers to be available universally. (The configure script
doesn't actually check for or define HAVE_LOCALE_H, which can cause
breakages. Simplify here, rather than making configure more complicated.)

--- plugins/i2c-proc/i2c-proc-plugin.c.orig	2020-02-10 12:40:35.000000000 +0000
+++ plugins/i2c-proc/i2c-proc-plugin.c
@@ -20,13 +20,8 @@
 #include <config.h>
 #endif /* HAVE_CONFIG_H */
 
-#ifdef HAVE_STDIO_H
 #include <stdio.h>
-#endif /* HAVE_STDIO_H */
-
-#ifdef HAVE_LOCALE_H
 #include <locale.h>
-#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
