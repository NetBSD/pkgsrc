$NetBSD: patch-src_Quad_XML.cc,v 1.1 2026/11/14 21:36:38 drixter Exp $

SunOS fix: Add fcntl.h which is needed

--- src/Quad_XML.cc.orig
+++ src/Quad_XML.cc
@@ -24,6 +24,7 @@
 #include <errno.h>
 #include <string.h>
 #include <sys/fcntl.h>   // for O_RDONLY
+#include <fcntl.h>
 #include <sys/stat.h>
 
 #include "Avec.hh"
