$NetBSD: patch-simgear_io_test__untar.cxx,v 1.1 2018/08/06 11:03:18 jperkin Exp $

SunOS needs alloca.h

--- simgear/io/test_untar.cxx.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/io/test_untar.cxx
@@ -7,6 +7,10 @@
 
 #include <iostream>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "untar.hxx"
 
 #include <simgear/misc/test_macros.hxx>
