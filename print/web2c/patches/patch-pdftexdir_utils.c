$NetBSD: patch-pdftexdir_utils.c,v 1.1 2020/01/11 00:31:05 ryoon Exp $

* Fix a cstdio is not found error.

--- pdftexdir/utils.c.orig	2017-11-14 23:50:55.000000000 +0000
+++ pdftexdir/utils.c
@@ -33,7 +33,6 @@ with this program.  If not, see <http://
 #include "ptexlib.h"
 #include <png.h>
 #ifdef POPPLER_VERSION
-#include <poppler-config.h>
 #define xpdfVersion POPPLER_VERSION
 #define xpdfString "poppler"
 #else
