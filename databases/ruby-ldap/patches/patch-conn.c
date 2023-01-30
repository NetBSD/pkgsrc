$NetBSD: patch-conn.c,v 1.1 2023/01/30 13:53:50 taca Exp $

* Stop using tainted Ruby strings.
* Stop using rb_cData for Ruby 3.2.

--- conn.c.orig	2023-01-30 13:49:20.297087468 +0000
+++ conn.c
@@ -688,7 +688,7 @@ rb_ldap_conn_get_option (VALUE self, VAL
 #endif
 #endif
 	  val = (data
-		 && *data) ? rb_tainted_str_new2 ((char *) (*data)) : Qnil;
+		 && *data) ? rb_str_new2 ((char *) (*data)) : Qnil;
 	  break;
 #ifdef LDAP_OPT_API_INFO
 	case LDAP_OPT_API_INFO:
@@ -781,7 +781,7 @@ rb_ldap_conn_err2string (VALUE self, VAL
 
   GET_LDAP_DATA (self, ldapdata);
   str = ldap_err2string (c_err);
-  return (str ? rb_tainted_str_new2 (str) : Qnil);
+  return (str ? rb_str_new2 (str) : Qnil);
 };
 
 VALUE
@@ -826,14 +826,14 @@ rb_ldap_internal_strcmp (const char *lef
 
   if (rb_ldap_sort_obj == Qtrue)
     {
-      res = rb_funcall (rb_tainted_str_new2 (left), rb_intern ("<=>"), 1,
-			rb_tainted_str_new2 (right));
+      res = rb_funcall (rb_str_new2 (left), rb_intern ("<=>"), 1,
+			rb_str_new2 (right));
     }
   else if (rb_ldap_sort_obj != Qnil)
     {
       res = rb_funcall (rb_ldap_sort_obj, rb_intern ("call"), 2,
-			rb_tainted_str_new2 (left),
-			rb_tainted_str_new2 (right));
+			rb_str_new2 (left),
+			rb_str_new2 (right));
     }
   else
     {
@@ -1855,7 +1855,7 @@ Init_ldap_conn ()
 {
   rb_ldap_sort_obj = Qnil;
 
-  rb_cLDAP_Conn = rb_define_class_under (rb_mLDAP, "Conn", rb_cData);
+  rb_cLDAP_Conn = rb_define_class_under (rb_mLDAP, "Conn", rb_cObject);
   rb_define_attr (rb_cLDAP_Conn, "referrals", 1, 0);
   rb_define_attr (rb_cLDAP_Conn, "controls", 1, 0);
   rb_define_attr (rb_cLDAP_Conn, "sasl_quiet", 1, 1);
