$NetBSD: patch-flow_audioiolibaudioio.cc,v 1.1 2012/04/02 12:16:30 markd Exp $

Fix build on OpenIndiana

--- flow/audioiolibaudioio.cc.orig	2007-10-08 09:47:09.000000000 +0000
+++ flow/audioiolibaudioio.cc
@@ -48,6 +48,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <string.h>
 #include <iostream>
 #include <algorithm>
 
