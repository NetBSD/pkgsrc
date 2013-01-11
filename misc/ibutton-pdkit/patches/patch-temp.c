$NetBSD: patch-temp.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- temp.c.orig	2013-01-11 01:31:28.000000000 +0000
+++ temp.c
@@ -62,7 +62,7 @@ int family_code;
 //----------------------------------------------------------------------
 //  Main Test for DS1920/DS1820 temperature measurement
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    float current_temp;
    char return_msg[128];
