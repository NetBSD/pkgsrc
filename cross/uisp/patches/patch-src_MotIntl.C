$NetBSD: patch-src_MotIntl.C,v 1.1 2011/12/05 22:44:08 joerg Exp $

--- src/MotIntl.C.orig	2011-12-05 20:37:28.000000000 +0000
+++ src/MotIntl.C
@@ -110,7 +110,7 @@ void TMotIntl::UploadMotorola(){
   do{
     /* convert to upper case */
     buf_len = strlen(line_buf);
-    for (int i=0;i<buf_len;i++){line_buf[i] = toupper(line_buf[i]);}
+    for (int i=0;i<buf_len;i++){line_buf[i] = toupper((unsigned char)line_buf[i]);}
   
     if (line_buf[0]!='S'){throw Error_Device("Bad Motorola file format.");}
     
@@ -246,7 +246,7 @@ void TMotIntl::UploadIntel(){
   do{
     /* convert to upper case */
     buf_len = strlen(line_buf);
-    for (int i=0;i<buf_len;i++){line_buf[i] = toupper(line_buf[i]);}
+    for (int i=0;i<buf_len;i++){line_buf[i] = toupper((unsigned char)line_buf[i]);}
   
     if (line_buf[0]!=':'){throw Error_Device("Bad Intel file format.");}
 
