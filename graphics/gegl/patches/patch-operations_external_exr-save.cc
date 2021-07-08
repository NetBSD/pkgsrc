$NetBSD: patch-operations_external_exr-save.cc,v 1.3 2021/07/08 21:29:49 markd Exp $

openexr3 patch

--- operations/external/exr-save.cc.orig	2021-03-27 19:13:57.953967000 +0000
+++ operations/external/exr-save.cc
@@ -45,6 +45,7 @@ extern "C" {
 #include <ImfChromaticities.h>
 #include <ImfStandardAttributes.h>
 #include <ImfArray.h>
+#include <ImfFrameBuffer.h>
 #include "ImathRandom.h"
 
 
