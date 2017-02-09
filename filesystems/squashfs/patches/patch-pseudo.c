$NetBSD: patch-pseudo.c
include sys/stat.h

--- pseudo.c.orig	2017-02-06 12:32:28.000000000 -0800
+++ pseudo.c	2017-02-06 12:32:46.000000000 -0800
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <sys/stat.h>
 #include <ctype.h>
 
 #include "pseudo.h"
