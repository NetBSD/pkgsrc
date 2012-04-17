$NetBSD: patch-src_uipp_mb_Main.C,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/mb/Main.C.orig	2000-05-20 17:49:40.000000000 +0000
+++ src/uipp/mb/Main.C
@@ -22,8 +22,7 @@ extern "C" void HCLXmInit();
 //
 const char *AssertMsgString = "Internal error detected at \"%s\":%d.\n";
 
-int main(unsigned int argc,
-	  char**       argv)
+int main(int argc, char **argv)
 {
 #if defined(HAVE_HCLXMINIT)
     HCLXmInit();
