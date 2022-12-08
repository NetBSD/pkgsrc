$NetBSD: patch-we__xterm.c,v 1.1 2022/12/08 08:51:56 vins Exp $

Fix warning about incompatible pointer type.

--- we_xterm.c.orig	2005-07-07 01:53:09.000000000 +0000
+++ we_xterm.c
@@ -95,7 +95,7 @@ int WpeDllInit(int *argc, char **argv)
  e_u_ini_size = e_ini_size;
  e_u_setlastpic = e_setlastpic;
  WpeMouseChangeShape = (void (*)(WpeMouseShape))WpeNullFunction;
- WpeMouseRestoreShape = (void (*)(WpeMouseShape))WpeNullFunction;
+ WpeMouseRestoreShape = WpeNullFunction;
 /* WpeMouseChangeShape = WpeXMouseChangeShape;
  WpeMouseRestoreShape = WpeXMouseRestoreShape;*/
  WpeDisplayEnd = WpeNullFunction;
