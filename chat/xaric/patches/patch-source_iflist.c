$NetBSD: patch-source_iflist.c,v 1.2 2013/07/21 11:29:55 shattered Exp $

--- iflist.c.orig	2001-11-24 09:07:57.000000000 +0100
+++ iflist.c	2012-01-24 20:36:11.838890687 +0100
@@ -38,6 +38,10 @@
 # include <assert.h>
 #endif
 
+#ifdef __sun
+#include <sys/sockio.h>
+#endif
+
 #include "irc.h"
 #include "ircaux.h"
 #include "iflist.h"
