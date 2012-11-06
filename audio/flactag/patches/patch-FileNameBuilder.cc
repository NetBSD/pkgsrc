$NetBSD: patch-FileNameBuilder.cc,v 1.2 2012/11/06 18:38:34 drochner Exp $

--- FileNameBuilder.cc.orig	2012-10-19 21:40:21.000000000 +0000
+++ FileNameBuilder.cc
@@ -30,6 +30,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <cstdio>
 
 #include <unac.h>
 
