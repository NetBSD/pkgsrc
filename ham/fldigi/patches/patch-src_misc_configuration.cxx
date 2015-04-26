$NetBSD: patch-src_misc_configuration.cxx,v 1.3 2015/04/26 03:04:59 mef Exp $

For DragonFly build to fix following problem:
misc/configuration.cxx: In member function 'void configuration::testCommPorts()':
misc/configuration.cxx:934:2: error: 'glob_t' was not declared in this scope
misc/configuration.cxx:934:9: error: expected ';' before 'gbuf'
gmake[3]: *** [fldigi-configuration.o] Error 1

--- src/misc/configuration.cxx.orig	2015-04-18 22:26:19.000000000 +0900
+++ src/misc/configuration.cxx	2015-04-26 11:26:35.000000000 +0900
@@ -863,7 +863,7 @@
 		"/dev/ttyACM%u",
 		"/dev/usb/ttyACM%u",
 		"/opt/vttyS%u"
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 		"/dev/tty%2.2u"
 #elif defined(__CYGWIN__)
 		"/dev/ttyS%u"
@@ -877,7 +877,7 @@
 
 #if defined(__WOE32__)
 #  define TTY_MAX 255
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define TTY_MAX 4
 #else
 #  define TTY_MAX 8
