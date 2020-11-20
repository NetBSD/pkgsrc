$NetBSD: patch-sgtk_sgtk.h,v 1.1 2020/11/20 15:15:24 nia Exp $

Avoid implicit function declaration.

From Debian:
https://sources.debian.org/patches/xscorch/0.2.1-1+nmu5/gdk-include/

--- sgtk/sgtk.h.orig	2009-04-26 17:39:48.000000000 +0000
+++ sgtk/sgtk.h
@@ -24,6 +24,7 @@
 #ifndef __sgtk_h_included
 #define __sgtk_h_included
 
+#include <gdk/gdk.h>
 
 /* This file implies xscorch.h. */
 #include <xscorch.h>
