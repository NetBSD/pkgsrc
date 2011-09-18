$NetBSD: patch-alias.c,v 1.1 2011/09/18 14:18:25 ryoon Exp $

--- alias.c.orig	2011-08-13 18:39:45 +0000
+++ alias.c
@@ -40,11 +40,11 @@
 # include <unistd.h>
 #endif /* HAVE_UNISTD_H */
 
+#include <errno.h>
 #include "sudo.h"
 #include "parse.h"
 #include "redblack.h"
 #include <gram.h>
-#include <errno.h>
 
 /*
  * Globals
