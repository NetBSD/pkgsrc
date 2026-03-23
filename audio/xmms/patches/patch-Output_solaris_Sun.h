$NetBSD: patch-Output_solaris_Sun.h,v 1.1 2026/03/23 13:11:30 nia Exp $

Fix implicit declaration of memset(3).

--- Output/solaris/Sun.h.orig	2026-03-23 12:23:58.230974725 +0000
+++ Output/solaris/Sun.h
@@ -32,6 +32,7 @@
 #include <stropts.h>
 
 #include <stdlib.h>
+#include <string.h>
 #include <stdio.h>
 
 #include "xmms/plugin.h"
