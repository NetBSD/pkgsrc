$NetBSD: patch-src-ILU_ilur_ilur.c,v 1.1 2019/08/28 13:12:15 maya Exp $

Don't expect a malloc.h header, lots of OSes don't have one
(freebsd, OS X).

malloc is, per standard, in stdlib.h

--- src-ILU/ilur/ilur.c.orig	2009-03-08 07:10:12.000000000 +0000
+++ src-ILU/ilur/ilur.c
@@ -1,6 +1,6 @@
 #include <string.h>
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include <IL/il.h>
 #include <IL/ilu.h>
