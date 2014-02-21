$NetBSD: patch-tcpillust.c,v 1.1 2014/02/21 20:31:08 joerg Exp $

--- tcpillust.c.orig	2014-02-20 23:18:55.000000000 +0000
+++ tcpillust.c
@@ -30,6 +30,7 @@
  */
 
 #define MAIN
+#define USE_INTERP_RESULT
 #include "tcpillust.h"
 
 static int init_clib __P((ClientData, Tcl_Interp *, int, char **));
@@ -69,11 +70,12 @@ float basesubratio;
 float substarttime;
 float subendtime;
 
-void
+int
 main(int argc, char* argv[]) 
 {
 	parser(argc, argv);
 	init_tk();
+	return 0;
 }
 
 void
