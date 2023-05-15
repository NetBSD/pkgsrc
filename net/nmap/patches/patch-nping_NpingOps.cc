$NetBSD: patch-nping_NpingOps.cc,v 1.1 2023/05/15 09:43:17 jperkin Exp $

INT_MAX needs climits.

--- nping/NpingOps.cc.orig	2022-08-31 18:39:58.000000000 +0000
+++ nping/NpingOps.cc
@@ -73,6 +73,7 @@
 #include "output.h"
 #include "common.h"
 
+#include <climits>
 
 /******************************************************************************
  *  Constructors and destructors                                              *
