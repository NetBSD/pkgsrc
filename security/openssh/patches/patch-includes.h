$NetBSD: patch-includes.h,v 1.4 2016/01/18 12:53:26 jperkin Exp $

Interix support

--- includes.h.orig	2015-08-21 04:49:03.000000000 +0000
+++ includes.h
@@ -127,6 +127,10 @@
 #ifdef HAVE_READPASSPHRASE_H
 # include <readpassphrase.h>
 #endif
+#ifdef HAVE_INTERIX
+# include <interix/env.h>
+# include <interix/security.h>
+#endif
 
 #ifdef HAVE_IA_H
 # include <ia.h>
