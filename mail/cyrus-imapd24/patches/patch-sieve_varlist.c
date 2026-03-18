$NetBSD: patch-sieve_varlist.c,v 1.1 2026/03/18 17:06:32 nia Exp $

Fix implicit declaration of strcmp(3).

--- sieve/varlist.c.orig	2026-03-18 16:45:00.161293497 +0000
+++ sieve/varlist.c
@@ -7,6 +7,7 @@
 
 #include "varlist.h"
 #include <memory.h>
+#include <string.h>
 #include "xmalloc.h"
 
 
