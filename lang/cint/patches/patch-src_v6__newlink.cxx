$NetBSD: patch-src_v6__newlink.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Fix C++ syntax: strlen(3), atoi(3), strcpy(3) aren't in the std:: namespace.

--- src/v6_newlink.cxx.orig	2007-03-15 17:59:30.000000000 +0000
+++ src/v6_newlink.cxx
@@ -7014,7 +7014,7 @@ int G__parse_parameter_link(char* paras)
     }
     else {
       if (type_name[0] == '\'') {
-        type_name[std::strlen(type_name)-1] = '\0';
+        type_name[strlen(type_name)-1] = '\0';
         typenum = G__defined_typename(type_name + 1);
       }
       else {
@@ -7022,7 +7022,7 @@ int G__parse_parameter_link(char* paras)
       }
     }
     ch = G__separate_parameter(paras, &os, c_reftype_const);
-    reftype_const = std::atoi(c_reftype_const);
+    reftype_const = atoi(c_reftype_const);
 #ifndef G__OLDIMPLEMENTATION1861
     if (typenum != -1) {
       reftype_const += G__newtype.isconst[typenum] * 10;
@@ -7037,14 +7037,14 @@ int G__parse_parameter_link(char* paras)
       para_default = (G__value*) -1;
       // The parameter default text will be quoted if it
       // contains spaces, we must remove the quotes.
-      int len = std::strlen(c_default);
+      int len = strlen(c_default);
       //assert(len > 2);
       if (len > 1 && (c_default[0] == '\'' || c_default[0] == '\"')) {
         c_default[len-1] = '\0';
         // The source and destination overlap, do it carefully.
         char buf[G__MAXNAME*2];
-        std::strcpy(buf, ((char*) c_default) + 1);
-        std::strcpy(c_default, buf);
+        strcpy(buf, ((char*) c_default) + 1);
+        strcpy(c_default, buf);
       }
     }
     ch = G__separate_parameter(paras, &os, c_paraname);
