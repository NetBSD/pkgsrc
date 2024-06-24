$NetBSD: patch-ocpnsrc_glu_libutil_error.c,v 1.1 2024/06/24 09:55:43 bouyer Exp $

Fix error: 'NULL' undeclared here (not in a function)

--- ocpnsrc/glu/libutil/error.c.orig	2024-06-24 10:56:58.976899062 +0200
+++ ocpnsrc/glu/libutil/error.c	2024-06-24 10:57:19.224768094 +0200
@@ -31,7 +31,7 @@
 #include "gluos.h"
 #include "gluint.h"
 #include <GL/glu.h>
-
+#include <stddef.h>
 
 struct token_string
 {
