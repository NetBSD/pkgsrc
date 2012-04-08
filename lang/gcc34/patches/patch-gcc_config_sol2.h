$NetBSD: patch-gcc_config_sol2.h,v 1.1 2012/04/08 20:45:15 ryoon Exp $

* Fix lack of __PIC__ and __pic__ in gcc -fPIC
  http://gcc.gnu.org/viewcvs/branches/csl-sol210-3_4-branch/gcc/config/sol2.h?r1=87927&r2=87928&pathrev=178719

--- gcc/config/sol2.h.orig	2004-07-17 21:18:58.000000000 +0000
+++ gcc/config/sol2.h
@@ -73,6 +73,11 @@ Boston, MA 02111-1307, USA.  */
 	    builtin_define ("_LARGEFILE64_SOURCE=1");	\
 	    builtin_define ("__EXTENSIONS__");		\
 	  }						\
+	if (flag_pic)					\
+	  {						\
+	    builtin_define ("__PIC__");			\
+	    builtin_define ("__pic__");			\
+	  }						\
 	TARGET_SUB_OS_CPP_BUILTINS();			\
     } while (0)
 
