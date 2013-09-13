$NetBSD: patch-src_misc_configuration.cxx,v 1.1 2013/09/13 06:35:55 mef Exp $

For DragonFly build to fix following problem:
misc/configuration.cxx: In member function 'void configuration::testCommPorts()':
misc/configuration.cxx:934:2: error: 'glob_t' was not declared in this scope
misc/configuration.cxx:934:9: error: expected ';' before 'gbuf'
gmake[3]: *** [fldigi-configuration.o] Error 1

--- src/misc/configuration.cxx.orig	2013-04-12 23:24:15.000000000 +0900
+++ src/misc/configuration.cxx	2013-04-18 21:29:15.000000000 +0900
@@ -925,7 +925,7 @@ void configuration::testCommPorts()
 
 #if defined(__WOE32__)
 #  define TTY_MAX 255
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define TTY_MAX 4
 #else
 #  define TTY_MAX 8
