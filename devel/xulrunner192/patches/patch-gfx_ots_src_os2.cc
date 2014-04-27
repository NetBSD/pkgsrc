$NetBSD: patch-gfx_ots_src_os2.cc,v 1.1 2014/04/27 07:54:01 wiz Exp $

Add header for offsetof().

--- gfx/ots/src/os2.cc.orig	2012-03-06 14:45:28.000000000 +0000
+++ gfx/ots/src/os2.cc
@@ -9,6 +9,8 @@
 // OS/2 - OS/2 and Windows Metrics
 // http://www.microsoft.com/opentype/otspec/os2.htm
 
+#include <stddef.h>
+
 namespace ots {
 
 bool ots_os2_parse(OpenTypeFile *file, const uint8_t *data, size_t length) {
