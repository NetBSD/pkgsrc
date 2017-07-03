$NetBSD: patch-src_hugin__script__interface_hsi.i,v 1.1 2017/07/03 20:48:04 adam Exp $

Vigra's class VT1 conflicts with '#define VT1' from sys/termios.h.

--- src/hugin_script_interface/hsi.i.orig	2017-06-01 22:41:27.000000000 +0000
+++ src/hugin_script_interface/hsi.i
@@ -27,6 +27,7 @@
 
 %{
 #define SWIG_FILE_WITH_INIT
+#undef VT1
 
 #include <hugin_shared.h>
 #include <appbase/DocumentData.h>
