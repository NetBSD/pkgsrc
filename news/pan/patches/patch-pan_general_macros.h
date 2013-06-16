$NetBSD: patch-pan_general_macros.h,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/general/macros.h.orig	2013-06-16 10:38:55.000000000 +0000
+++ pan/general/macros.h
@@ -28,23 +28,23 @@
 **/
 
 #define foreach(Type,var,itname) \
-  for (Type::iterator itname(var.begin()), \
-                            itname##end(var.end()); itname!=itname##end; \
+  for (Type::iterator itname((var).begin()), \
+                            itname##end((var).end()); itname!=itname##end; \
                             ++itname)
 
 #define foreach_const(Type,var,itname) \
-  for (Type::const_iterator itname(var.begin()), \
-                            itname##end(var.end()); itname!=itname##end; \
+  for (Type::const_iterator itname((var).begin()), \
+                            itname##end((var).end()); itname!=itname##end; \
                             ++itname)
 
 #define foreach_r(Type,var,itname) \
-  for (Type::reverse_iterator itname(var.rbegin()), \
-                              itname##end(var.rend()); itname!=itname##end; \
+  for (Type::reverse_iterator itname((var).rbegin()), \
+                              itname##end((var).rend()); itname!=itname##end; \
                               ++itname)
 
 #define foreach_const_r(Type,var,itname) \
-  for (Type::const_reverse_iterator itname(var.rbegin()), \
-                           itname##end(var.rend()); itname!=itname##end; \
+  for (Type::const_reverse_iterator itname((var).rbegin()), \
+                           itname##end((var).rend()); itname!=itname##end; \
                            ++itname)
 
 /**
