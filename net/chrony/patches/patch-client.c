$NetBSD: patch-client.c,v 1.1 2021/03/12 09:57:18 nia Exp $

NetBSD provides libedit-as-readline, but chrony wants libedit.
just include the fake readline header.

--- client.c.orig	2020-10-07 15:27:34.000000000 +0000
+++ client.c
@@ -44,7 +44,7 @@
 #include "util.h"
 
 #ifdef FEAT_READLINE
-#include <editline/readline.h>
+#include <readline.h>
 #endif
 
 /* ================================================== */
