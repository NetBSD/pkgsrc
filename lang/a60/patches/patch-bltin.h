$NetBSD: patch-bltin.h,v 1.1 2015/02/21 13:07:02 mef Exp $

bltin.o: In function `bltin_rand':
bltin.c:(.text+0x1ff): warning: warning: reference to compatibility time(); include <time.h> for correct reference
=
--- bltin.h~	2014-07-11 00:19:30.000000000 +0900
+++ bltin.h	2015-02-21 21:57:13.000000000 +0900
@@ -31,6 +31,7 @@
 # define P(x)  ()
 #endif
 
+#include <time.h>
 
 extern void init_bltin P((void));
 
