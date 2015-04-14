$NetBSD: patch-acinclude.m4,v 1.1 2015/04/14 14:23:14 joerg Exp $

--- acinclude.m4.orig	2015-04-10 14:47:05.000000000 +0000
+++ acinclude.m4
@@ -904,7 +904,11 @@ EOF
 	AC_LANG_PUSH(C)
     AC_TRY_COMPILE([],[{}],[
       bc_cv_as_noexecstack=yes
-      bc_gnu_stack='.section .note.GNU-stack,"",@progbits; .previous'
+      if [ $bc_target_arch = arm ]; then
+        bc_gnu_stack='.section .note.GNU-stack,"",%progbits; .previous'
+      else
+        bc_gnu_stack='.section .note.GNU-stack,"",@progbits; .previous'
+      fi
       ],[
       CFLAGS=$CFLAGS_save
       CXXFLAGS=$CXXFLAGS_save
