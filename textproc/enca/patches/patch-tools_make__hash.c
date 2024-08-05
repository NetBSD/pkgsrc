$NetBSD: patch-tools_make__hash.c,v 1.1 2024/08/05 13:23:25 tnn Exp $

include <string.h> for memmove(3)

--- tools/make_hash.c.orig	2024-08-05 14:51:44.677421845 +0000
+++ tools/make_hash.c
@@ -23,6 +23,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 
 #ifdef HAVE_STRING_H
 #  include <string.h>
