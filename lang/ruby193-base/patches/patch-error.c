$NetBSD$

Fix for CVE-2011-1005 which turned out affected to Ruby 1.9.3  from
Ruby's repository r37068.  Now it assigned CVE-2012-4464 and CVE-2012-4466.

--- error.c.orig	2012-02-25 12:32:19.000000000 +0000
+++ error.c
@@ -569,7 +569,6 @@ exc_to_s(VALUE exc)
 
     if (NIL_P(mesg)) return rb_class_name(CLASS_OF(exc));
     r = rb_String(mesg);
-    OBJ_INFECT(r, exc);
     return r;
 }
 
@@ -853,11 +852,7 @@ name_err_to_s(VALUE exc)
 
     if (NIL_P(mesg)) return rb_class_name(CLASS_OF(exc));
     StringValue(str);
-    if (str != mesg) {
-	rb_iv_set(exc, "mesg", mesg = str);
-    }
-    OBJ_INFECT(mesg, exc);
-    return mesg;
+    return str;
 }
 
 /*
@@ -988,7 +983,6 @@ name_err_mesg_to_str(VALUE obj)
 	args[2] = d;
 	mesg = rb_f_sprintf(NAME_ERR_MESG_COUNT, args);
     }
-    OBJ_INFECT(mesg, obj);
     return mesg;
 }
 
