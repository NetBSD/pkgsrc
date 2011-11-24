$NetBSD: patch-src_fdc_TC8566AF.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/fdc/TC8566AF.cc.orig	2011-11-24 02:42:35.000000000 +0000
+++ src/fdc/TC8566AF.cc
@@ -8,6 +8,7 @@
 #include "TC8566AF.hh"
 #include "DiskDrive.hh"
 #include "MSXException.hh"
+#include <string.h>
 
 namespace openmsx {
 
