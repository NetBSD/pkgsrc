$NetBSD: patch-src_kseq.h,v 1.1 2022/02/27 01:57:27 bacon Exp $

# Unbundle htslib

--- src/kseq.h.orig	2022-02-26 16:37:08.929391121 +0000
+++ src/kseq.h
@@ -27,6 +27,8 @@ SOFTWARE.
 #include <ctype.h>
 #include <string.h>
 #include <stdlib.h>
+// Prevent redefinition of kstring_t below
+#include <htslib/kstring.h>
 
 #define KS_SEP_SPACE 0 // isspace(): \t, \n, \v, \f, \r
 #define KS_SEP_TAB   1 // isspace() && !' '
