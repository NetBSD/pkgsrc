$NetBSD: patch-unix-config.cxx,v 1.2 2012/12/01 15:28:03 darcy Exp $

- Add Dragonfly support

--- src/ptlib/unix/config.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/config.cxx
@@ -49,6 +49,6 @@
 #define	EXTENSION		".ini"
 #define	ENVIRONMENT_CONFIG_STR	"/\~~environment~~\/"
 
-#if defined(P_MACOSX) || defined(P_SOLARIS) || defined(P_FREEBSD)
+#if defined(P_MACOSX) || defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_DRAGONFLY)
 #define environ (NULL)
 #endif
