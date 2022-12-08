$NetBSD: patch-we__main.c,v 1.1 2022/12/08 08:51:56 vins Exp $

Repair bug in error message when immediately running out of memory.

--- we_main.c.orig	2005-07-07 01:53:09.000000000 +0000
+++ we_main.c
@@ -307,8 +307,10 @@ int main(int argc, char **argv)
  int so = 0, sd = 1;
  char *tp;
 
- if ((cn = (ECNT *)MALLOC(sizeof(ECNT))) == NULL)
-  e_error(e_msg[ERR_LOWMEM], 2, fb);
+ if ((cn = (ECNT *)MALLOC(sizeof(ECNT))) == NULL) {
+ 	printf(" Fatal Error: %s\n", e_msg[ERR_LOWMEM]);
+ 	return 0;
+ }
  ECNT_Init(cn);
  e_ini_unix(&argc, argv);
  e_switch_screen(1);
