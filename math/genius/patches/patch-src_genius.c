$NetBSD: patch-src_genius.c,v 1.1 2014/09/23 22:52:01 jperkin Exp $

Don't include termcap.h on SunOS.

--- src/genius.c.orig	2013-04-24 23:18:19.000000000 +0000
+++ src/genius.c
@@ -61,8 +61,10 @@
 #include <term.h>
 #endif
 #else
+#ifndef __sun
 #include <termcap.h>
 #endif
+#endif
 
 #include <vicious.h>
 
