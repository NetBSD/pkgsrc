$NetBSD: patch-libtest_main.cc,v 1.1 2013/10/04 07:03:37 fhajny Exp $

Prefer strrchr() to rindex().

--- libtest/main.cc.orig	2013-05-03 04:59:32.000000000 +0000
+++ libtest/main.cc
@@ -90,7 +90,7 @@ int main(int argc, char *argv[])
   std::string wildcard;
   std::string binary_name;
 
-  const char *just_filename= rindex(argv[0], '/');
+  const char *just_filename= strrchr(argv[0], '/');
   if (just_filename)
   {
     just_filename++;
