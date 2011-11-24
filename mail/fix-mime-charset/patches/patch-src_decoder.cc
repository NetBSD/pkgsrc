$NetBSD: patch-src_decoder.cc,v 1.1 2011/11/24 13:56:02 joerg Exp $

--- src/decoder.cc.orig	2011-11-24 00:54:13.000000000 +0000
+++ src/decoder.cc
@@ -2,2 +2,3 @@
 
+#include <string.h>
 #include "decoder.h"
