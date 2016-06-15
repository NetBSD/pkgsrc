$NetBSD: patch-include_Inventor_SbBasic.h,v 1.1 2016/06/15 18:55:18 rumko Exp $

https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=667375

--- include/Inventor/SbBasic.h.orig	2010-03-02 13:20:09.000000000 +0000
+++ include/Inventor/SbBasic.h
@@ -24,6 +24,7 @@
  *
 \**************************************************************************/
 
+#include <Inventor/C/errors/debugerror.h>
 #include <Inventor/C/basic.h>
 
 /* ********************************************************************** */
