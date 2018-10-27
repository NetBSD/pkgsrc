$NetBSD: patch-source_compiler_aslwalks.c,v 1.1 2018/10/27 21:44:53 abs Exp $

Avoid potential sprintf buffer overflow reported by gcc 8.2.0

--- source/compiler/aslwalks.c.orig	2016-09-30 16:43:57.000000000 +0000
+++ source/compiler/aslwalks.c
@@ -511,7 +511,7 @@ AnOperandTypecheckWalkEnd (
                 AnFormatBtype (StringBuffer, ThisNodeBtype);
                 AnFormatBtype (StringBuffer2, RequiredBtypes);
 
-                sprintf (MsgBuffer, "[%s] found, %s operator requires [%s]",
+                snprintf (MsgBuffer, sizeof(MsgBuffer), "[%s] found, %s operator requires [%s]",
                     StringBuffer, OpInfo->Name, StringBuffer2);
 
                 AslError (ASL_ERROR, ASL_MSG_INVALID_TYPE,
