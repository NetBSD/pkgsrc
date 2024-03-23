$NetBSD: patch-ext_stringio_stringio.c,v 1.1 2024/03/23 14:28:48 taca Exp $

Update stringio to 3.0.1.2 to fix for CVE-2024-27280.

--- ext/stringio/stringio.c.orig	2023-03-30 10:53:51.000000000 +0000
+++ ext/stringio/stringio.c
@@ -12,7 +12,7 @@
 
 **********************************************************************/
 
-#define STRINGIO_VERSION "3.0.1"
+#define STRINGIO_VERSION "3.0.1.2"
 
 #include "ruby.h"
 #include "ruby/io.h"
@@ -984,7 +984,7 @@ strio_unget_bytes(struct StringIO *ptr, 
     len = RSTRING_LEN(str);
     rest = pos - len;
     if (cl > pos) {
-	long ex = (rest < 0 ? cl-pos : cl+rest);
+	long ex = cl - (rest < 0 ? pos : len);
 	rb_str_modify_expand(str, ex);
 	rb_str_set_len(str, len + ex);
 	s = RSTRING_PTR(str);
