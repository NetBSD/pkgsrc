$NetBSD: patch-strrstr.c,v 1.1 2011/12/06 19:55:43 joerg Exp $

--- strrstr.c.orig	2011-12-06 15:46:38.000000000 +0000
+++ strrstr.c
@@ -1,3 +1,4 @@
+#include <string.h>
 /* Strrstr.c, included for those computers that do not have it. */
 /* Written by Kent Irwin, irwin@leland.stanford.edu.  I am
    responsible for bugs */
