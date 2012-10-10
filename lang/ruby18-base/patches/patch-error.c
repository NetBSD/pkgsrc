$NetBSD: patch-error.c,v 1.1.2.2 2012/10/10 12:13:08 tron Exp $

More fix to CVE-2011-1005 from discuttion on oss-security mailing list.

--- error.c.orig	2011-02-18 12:32:35.000000000 +0000
+++ error.c
@@ -665,9 +665,6 @@ name_err_to_s(exc)
 
     if (NIL_P(mesg)) return rb_class_name(CLASS_OF(exc));
     StringValue(str);
-    if (str != mesg) {
-	OBJ_INFECT(str, mesg);
-    }
     return str;
 }
 
