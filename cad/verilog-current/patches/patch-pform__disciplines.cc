$NetBSD: patch-pform__disciplines.cc,v 1.1 2011/11/26 17:10:24 joerg Exp $

--- pform_disciplines.cc.orig	2011-11-26 03:29:20.000000000 +0000
+++ pform_disciplines.cc
@@ -27,8 +27,8 @@ map<perm_string,ivl_nature_t> natures;
 map<perm_string,ivl_discipline_t> disciplines;
 map<perm_string,ivl_nature_t> access_function_nature;
 
-static perm_string nature_name = perm_string::perm_string();
-static perm_string nature_access = perm_string::perm_string();
+static perm_string nature_name = perm_string();
+static perm_string nature_access = perm_string();
 
 void pform_start_nature(const char*name)
 {
@@ -82,8 +82,8 @@ void pform_end_nature(const struct vllty
 	// expressions that use the access function can find it.
       access_function_nature[nature_access] = tmp;
 
-      nature_name = perm_string::perm_string();
-      nature_access = perm_string::perm_string();
+      nature_name = perm_string();
+      nature_access = perm_string();
 }
 
 
@@ -171,7 +171,7 @@ void pform_end_discipline(const struct v
       FILE_NAME(tmp, loc);
 
 	/* Clear the static variables for the next item. */
-      discipline_name = perm_string::perm_string();
+      discipline_name = perm_string();
       discipline_domain = IVL_DIS_NONE;
       discipline_potential = 0;
       discipline_flow = 0;
