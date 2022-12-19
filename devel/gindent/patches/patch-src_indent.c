$NetBSD: patch-src_indent.c,v 1.1 2022/12/19 10:21:27 wiz Exp $

configure does not define HAVE_LOCALE_H
http://savannah.gnu.org/support/?110390

--- src/indent.c.orig	2018-09-02 07:47:27.000000000 +0000
+++ src/indent.c
@@ -71,9 +71,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
-#ifdef HAVE_LOCALE_H
 #include <locale.h>
-#endif
 #include "indent.h"
 #include "backup.h"
 #include "code_io.h"
