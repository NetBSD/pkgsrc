$NetBSD: patch-type1.c,v 1.1 2012/04/26 15:18:55 minskim Exp $

The Error macro doesn't return a value, but PSFakePop() should return
a DOUBLE. gcc seems to accept this, clang does not.

--- type1.c.orig	2012-04-26 13:37:31.000000000 +0000
+++ type1.c
@@ -125,8 +125,12 @@ int currentchar = -1; /* for error repor
 #define CC IfTrace1(TRUE, "'%03o ", currentchar)
 
 #define Error {errflag = TRUE; return;}
+
+#define Error_rd {errflag = TRUE; return 0.0;}
  
 #define Error0(errmsg) { CC; IfTrace0(TRUE, errmsg); Error;}
+
+#define Error0_rd(errmsg) { CC; IfTrace0(TRUE, errmsg); Error_rd;}
  
 #define Error1(errmsg,arg) { CC; IfTrace1(TRUE, errmsg, arg); Error;}
  
@@ -780,7 +784,7 @@ static void PSFakePush(Num)
 static DOUBLE PSFakePop ()
 {
   if (PSFakeTop >= 0) return(PSFakeStack[PSFakeTop--]);
-  else Error0("PSFakePop : Stack empty\n");
+  else Error0_rd("PSFakePop : Stack empty\n");
   /*NOTREACHED*/
 }
  
