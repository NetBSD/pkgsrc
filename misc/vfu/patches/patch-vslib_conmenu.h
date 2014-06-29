$NetBSD: patch-vslib_conmenu.h,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vslib/conmenu.h~	2002-04-26 07:24:06.000000000 +0000
+++ vslib/conmenu.h
@@ -18,7 +18,7 @@ struct  ToggleEntry
   int  key;
   char name[64];
   int  *data;
-  char **states;
+  const char *const *states;
 };
 
 struct ConMenuInfo
