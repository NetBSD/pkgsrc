$NetBSD: patch-qcadlib_src_information_rs__information.h,v 1.1 2011/09/23 03:26:57 ryoon Exp $

--- qcadlib/src/information/rs_information.h.orig	2005-11-22 11:52:39.000000000 +0000
+++ qcadlib/src/information/rs_information.h
@@ -31,7 +31,7 @@
 #include "rs_line.h"
 #include "rs_arc.h"
 
-
+#include <cstdlib>
 
 /**
  * Class for getting information about entities. This includes
