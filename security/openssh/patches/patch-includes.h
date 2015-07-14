$NetBSD: patch-includes.h,v 1.2.14.1 2015/07/14 22:03:39 tron Exp $

Interix support

--- includes.h.orig	2015-07-01 02:35:31.000000000 +0000
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
