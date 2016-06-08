$NetBSD: patch-caretx.c,v 1.1 2016/06/08 17:39:30 he Exp $

NetBSD's implementation sometimes returns "/"; reject that too.

--- caretx.c.orig	2016-03-01 12:33:01.000000000 +0000
+++ caretx.c
@@ -121,8 +121,10 @@ Perl_set_caret_X(pTHX) {
        to the executable (or returning an error from the readlink). Any
        valid path has a '/' in it somewhere, so use that to validate the
        result. See http://www.freebsd.org/cgi/query-pr.cgi?pr=35703
+
+       NetBSD's implementation sometimes returns "/"; reject that too.
     */
-    if (len > 0 && memchr(buf, '/', len)) {
+    if (len > 1 && memchr(buf, '/', len)) {
         sv_setpvn(caret_x, buf, len);
         return;
     }
