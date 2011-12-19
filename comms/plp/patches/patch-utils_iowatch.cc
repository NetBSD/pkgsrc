$NetBSD: patch-utils_iowatch.cc,v 1.1 2011/12/19 13:44:08 wiz Exp $

Remove unnecessary header.

--- utils/iowatch.cc.orig	1999-04-12 21:17:04.000000000 +0000
+++ utils/iowatch.cc
@@ -23,7 +23,6 @@
 #include <stdio.h>
 #include <sys/time.h>
 #include <sys/types.h>
-#include <stream.h>
 #include <memory.h>
 
 #include "bool.h"
