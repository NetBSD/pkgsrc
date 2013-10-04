$NetBSD: patch-examples_reverse__client__bg.cc,v 1.1 2013/10/04 07:03:37 fhajny Exp $

Need unistd.h for STDOUT_FILENO.

--- examples/reverse_client_bg.cc.orig	2013-02-14 11:34:29.000000000 +0000
+++ examples/reverse_client_bg.cc
@@ -43,6 +43,7 @@
 #include <iomanip>
 #include <iostream>
 #include <string>
+#include <unistd.h>
 
 #include <libgearman/gearman.h>
 #include <boost/program_options.hpp>
