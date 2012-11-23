$NetBSD: patch-gnuradio-core_src_lib_io_ppio_ppdev.cc,v 1.1 2012/11/23 20:46:41 markd Exp $

include <unistd.h> for close() and gcc4.7

--- gnuradio-core/src/lib/io/ppio_ppdev.cc.orig	2010-06-02 00:57:52.000000000 +0000
+++ gnuradio-core/src/lib/io/ppio_ppdev.cc
@@ -28,6 +28,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <iostream>
 #include <errno.h>
 #include <stdio.h>
