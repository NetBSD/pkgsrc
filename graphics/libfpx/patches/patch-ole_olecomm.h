$NetBSD: patch-ole_olecomm.h,v 1.1 2020/01/19 11:07:56 nros Exp $

* use autoconf to select endian header to make the package build on more
  platforms (illumos)

--- ole/olecomm.h.orig	2020-01-19 10:31:16.620919697 +0000
+++ ole/olecomm.h
@@ -65,9 +65,11 @@
 
 // value to define if the file is to be read/written in Intel mode or not
 # if defined(_UNIX)
-#  ifdef __linux__
+#  ifdef HAVE_ENDIAN_H
 #   include <endian.h>
-#  elif defined(__sun)
+#  elif defined(HAVE_SYS_ENDIAN_H)
+#   include <sys/endian.h>
+#  elif defined(HAVE_SOLARIS_H)
 #   include <solaris.h>
 #  else
 #   include <machine/endian.h>
