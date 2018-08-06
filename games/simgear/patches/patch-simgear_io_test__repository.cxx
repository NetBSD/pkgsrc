$NetBSD: patch-simgear_io_test__repository.cxx,v 1.1 2018/08/06 11:03:18 jperkin Exp $

SunOS needs alloca.h

--- simgear/io/test_repository.cxx.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/io/test_repository.cxx
@@ -5,6 +5,10 @@
 #include <errno.h>
 #include <fcntl.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include <boost/algorithm/string/case_conv.hpp>
 
 #include <simgear/simgear_config.h>
