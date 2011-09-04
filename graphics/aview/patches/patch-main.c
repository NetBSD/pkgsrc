$NetBSD: patch-main.c,v 1.1 2011/09/04 08:54:03 obache Exp $

* include <stdlib.h> for exit(3).
* include <string.h> for strncpy(3).

--- main.c.orig	2001-04-25 16:00:06.000000000 +0000
+++ main.c
@@ -1,3 +1,5 @@
+#include <stdlib.h>
+#include <string.h>
 #include <aalib.h>
 #include "image.h"
 #include "ui.h"
