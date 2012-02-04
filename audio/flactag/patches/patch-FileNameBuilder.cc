$NetBSD: patch-FileNameBuilder.cc,v 1.1 2012/02/04 09:26:11 sbd Exp $

--- FileNameBuilder.cc.orig	2012-02-04 08:44:33.120854935 +0000
+++ FileNameBuilder.cc
@@ -27,6 +27,7 @@
 #include "FileNameBuilder.h"
 
 #include <stdlib.h>
+#include <cstdio>
 
 #include <unac.h>
 
