$NetBSD: patch-source_compiler_aslanalyze.c,v 1.1 2018/10/27 21:44:53 abs Exp $

Avoid potential sprintf buffer overflow reported by gcc 8.2.0

--- source/compiler/aslanalyze.c.orig	2016-09-30 16:43:56.000000000 +0000
+++ source/compiler/aslanalyze.c
@@ -355,7 +355,7 @@ AnCheckMethodReturnValue (
          */
         if (ThisNodeBtype != 0)
         {
-            sprintf (MsgBuffer,
+            snprintf (MsgBuffer, sizeof(MsgBuffer),
                 "Method returns [%s], %s operator requires [%s]",
                 StringBuffer, OpInfo->Name, StringBuffer2);
 
