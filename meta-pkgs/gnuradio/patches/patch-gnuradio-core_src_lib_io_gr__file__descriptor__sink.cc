$NetBSD: patch-gnuradio-core_src_lib_io_gr__file__descriptor__sink.cc,v 1.1 2012/10/09 17:25:16 marino Exp $

Fix "close not declared in this scope" error on gcc 4.7

--- gnuradio-core/src/lib/io/gr_file_descriptor_sink.cc.orig	2010-06-02 00:57:52.000000000 +0000
+++ gnuradio-core/src/lib/io/gr_file_descriptor_sink.cc
@@ -33,6 +33,7 @@
 #include <fcntl.h>
 #include <stdexcept>
 #include <stdio.h>
+#include <unistd.h>
 
 
 gr_file_descriptor_sink::gr_file_descriptor_sink (size_t itemsize, int fd)
