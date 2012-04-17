$NetBSD: patch-src_uipp_prompter_Main.C,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/prompter/Main.C.orig	2000-05-16 18:52:59.000000000 +0000
+++ src/uipp/prompter/Main.C
@@ -17,8 +17,7 @@ extern "C" void HCLXmInit();
 #endif
 
 
-int main(unsigned int argc,
-	  char**       argv)
+int main(int argc, char **argv)
 {
 #if defined(HAVE_HCLXMINIT)
      HCLXmInit();
