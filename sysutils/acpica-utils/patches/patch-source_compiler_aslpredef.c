$NetBSD: patch-source_compiler_aslpredef.c,v 1.1 2018/10/27 21:44:53 abs Exp $

Avoid potential sprintf buffer overflow reported by gcc 8.2.0

--- source/compiler/aslpredef.c.orig	2016-09-30 16:43:57.000000000 +0000
+++ source/compiler/aslpredef.c
@@ -162,7 +162,7 @@ ApCheckForPredefinedMethod (
             AcpiUtGetExpectedReturnTypes (StringBuffer,
                 ThisName->Info.ExpectedBtypes);
 
-            sprintf (MsgBuffer, "%s required for %4.4s",
+            snprintf (MsgBuffer, sizeof(MsgBuffer), "%s required for %4.4s",
                 StringBuffer, ThisName->Info.Name);
 
             AslError (ASL_WARNING, ASL_MSG_RESERVED_RETURN_VALUE, Op,
@@ -700,12 +700,12 @@ TypeErrorExit:
 
     if (PackageIndex == ACPI_NOT_PACKAGE_ELEMENT)
     {
-        sprintf (MsgBuffer, "%4.4s: found %s, %s required",
+        snprintf (MsgBuffer, sizeof(MsgBuffer), "%4.4s: found %s, %s required",
             PredefinedName, TypeName, StringBuffer);
     }
     else
     {
-        sprintf (MsgBuffer, "%4.4s: found %s at index %u, %s required",
+        snprintf (MsgBuffer, sizeof(MsgBuffer), "%4.4s: found %s at index %u, %s required",
             PredefinedName, TypeName, PackageIndex, StringBuffer);
     }
 
