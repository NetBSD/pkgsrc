$NetBSD: patch-ytnef.c,v 1.1 2012/11/19 02:56:05 joerg Exp $

--- ytnef.c.orig	2012-11-18 23:24:09.000000000 +0000
+++ ytnef.c
@@ -565,7 +565,7 @@ void TNEFPrintDate(dtr Date) {
 int TNEFHexBreakdown STD_ARGLIST {
     int i;
     if (TNEF->Debug == 0) 
-        return;
+        return 0;
 
     printf("%s: [%i bytes] \n", TNEFList[id].name, size);
 
@@ -574,13 +574,14 @@ int TNEFHexBreakdown STD_ARGLIST {
         if ((i+1)%16 == 0) printf("\n");
     }
     printf("\n");
+    return 0;
 }
     
 // -----------------------------------------------------------------------------
 int TNEFDetailedPrint STD_ARGLIST {
     int i;
     if (TNEF->Debug == 0) 
-        return;
+        return 0;
 
     printf("%s: [%i bytes] \n", TNEFList[id].name, size);
 
@@ -588,6 +589,7 @@ int TNEFDetailedPrint STD_ARGLIST {
         printf("%c", data[i]);
     }
     printf("\n");
+    return 0;
 }
 
 // -----------------------------------------------------------------------------
