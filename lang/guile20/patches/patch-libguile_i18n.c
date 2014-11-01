$NetBSD: patch-libguile_i18n.c,v 1.1 2014/11/01 13:24:37 wiz Exp $

NetBSD provides newlocale and strcoll_l, but not uselocale.
http://debbugs.gnu.org/cgi/bugreport.cgi?bug=18898

--- libguile/i18n.c.orig	2014-01-21 21:25:11.000000000 +0000
+++ libguile/i18n.c
@@ -40,7 +40,7 @@
 #include <unicase.h>
 #include <unistr.h>
 
-#if (defined HAVE_NEWLOCALE) && (defined HAVE_STRCOLL_L)
+#if (defined HAVE_NEWLOCALE) && (defined HAVE_STRCOLL_L) && (defined HAVE_USELOCALE)
 /* The GNU thread-aware locale API is documented in ``Thread-Aware Locale
    Model, a Proposal'', by Ulrich Drepper:
 
