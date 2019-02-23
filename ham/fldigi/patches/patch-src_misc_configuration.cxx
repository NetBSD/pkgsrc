$NetBSD: patch-src_misc_configuration.cxx,v 1.4 2019/02/23 11:30:03 mef Exp $

For DragonFly build to fix following problem:
misc/configuration.cxx: In member function 'void configuration::testCommPorts()':
misc/configuration.cxx:934:2: error: 'glob_t' was not declared in this scope
misc/configuration.cxx:934:9: error: expected ';' before 'gbuf'
gmake[3]: *** [fldigi-configuration.o] Error 1

--- src/misc/configuration.cxx.orig	2019-02-18 23:47:43.000000000 +0900
+++ src/misc/configuration.cxx	2019-02-23 18:33:27.726856173 +0900
@@ -906,7 +906,7 @@
 		"/dev/usb/ttyACM%u",
 		"/dev/rfcomm%u",
 		"/opt/vttyS%u"
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 		"/dev/tty%2.2u"
 #elif defined(__CYGWIN__)
 		"/dev/ttyS%u"
@@ -920,7 +920,7 @@
 
 #if defined(__WOE32__)
 #  define TTY_MAX 255
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define TTY_MAX 4
 #else
 #  define TTY_MAX 8
