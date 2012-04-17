$NetBSD: patch-src_uipp_dxui_Main.C,v 1.1 2012/04/17 17:44:02 joerg Exp $

--- src/uipp/dxui/Main.C.orig	2005-12-07 17:50:53.000000000 +0000
+++ src/uipp/dxui/Main.C
@@ -48,8 +48,7 @@ extern unsigned long _etext;
 //
 const char *AssertMsgString = "Internal error detected at \"%s\":%d.\n";
  
-int main(unsigned int argc,
-	  char**       argv)
+int main(int argc, char **argv)
 {
 #if defined(HAVE_HCLXMINIT)
 // The following is not needed with the recent Exceed XDK. If you're
