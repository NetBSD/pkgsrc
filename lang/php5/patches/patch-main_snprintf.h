$NetBSD: patch-main_snprintf.h,v 1.1 2011/03/21 16:34:28 taca Exp $

--- main/snprintf.h.orig	2010-01-03 09:23:27.000000000 +0000
+++ main/snprintf.h
@@ -12,7 +12,7 @@
    | obtain it through the world-wide-web, please send a note to          |
    | license@php.net so we can mail you a copy immediately.               |
    +----------------------------------------------------------------------+
-   | Author: Stig Sæther Bakken <ssb@php.net>                             |
+   | Author: Stig SÃ¦ther Bakken <ssb@php.net>                             |
    |         Marcus Boerger <helly@php.net>                               |
    +----------------------------------------------------------------------+
 */
@@ -148,6 +148,17 @@ extern char * ap_php_conv_10(register wi
 extern char * ap_php_conv_p2(register u_wide_int num, register int nbits,
 		 char format, char *buf_end, register int *len);
 
+/* The maximum precision that's allowed for float conversion. Does not include
+ * decimal separator, exponent, sign, terminator. Currently does not affect
+ * the modes e/f, only g/k/H, as those have a different limit enforced at
+ * another level (see NDIG in php_conv_fp()).
+ * Applies to the formatting functions of both spprintf.c and snprintf.c, which
+ * use equally sized buffers of MAX_BUF_SIZE = 512 to hold the result of the
+ * call to php_gcvt().
+ * This should be reasonably smaller than MAX_BUF_SIZE (I think MAX_BUF_SIZE - 9
+ * should be enough, but let's give some more space) */
+#define FORMAT_CONV_MAX_PRECISION 500
+
 #endif /* SNPRINTF_H */
 
 /*
