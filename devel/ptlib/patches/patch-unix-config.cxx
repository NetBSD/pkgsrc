$NetBSD: patch-unix-config.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- src/ptlib/unix/config.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/config.cxx
@@ -49,7 +49,7 @@
 #define	EXTENSION		".ini"
 #define	ENVIRONMENT_CONFIG_STR	"/\~~environment~~\/"
 
-#if defined(P_MACOSX) || defined(P_SOLARIS) || defined(P_FREEBSD)
+#if defined(P_MACOSX) || defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_DRAGONFLY)
 #define environ (NULL)
 #endif
 
