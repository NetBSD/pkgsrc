$NetBSD: patch-simgear_io_untar.cxx,v 1.1 2018/08/06 11:03:18 jperkin Exp $

SunOS needs alloca.h

--- simgear/io/untar.cxx.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/io/untar.cxx
@@ -17,6 +17,10 @@
 
 #include <simgear_config.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "untar.hxx"
 
 #include <cstdlib>
