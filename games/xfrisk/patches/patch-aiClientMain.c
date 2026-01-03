$NetBSD: patch-aiClientMain.c,v 1.1 2026/01/03 04:08:45 dholland Exp $

Silence pointer cast warnings.

--- aiClientMain.c~	1999-11-27 18:19:33.000000000 +0000
+++ aiClientMain.c
@@ -349,7 +349,7 @@ void AI_Start(Int32 argc, CString *argv)
   RISK_SetAllocationStateOfSpecies(i, ALLOC_COMPLETE);
 
   /* Let the player do one-time initializations */
-  __AI_Callback(NULL, AI_INIT_ONCE, (void *)iSpeciesID); 
+  __AI_Callback(NULL, AI_INIT_ONCE, (void *)(intptr_t)iSpeciesID); 
 }
      
 
@@ -496,7 +496,7 @@ void CBK_IncomingMessage(Int32 iMessType
 	  {
             fGameInitialized = TRUE;
             /* Let the player do initializations of game */
-            __AI_Callback(NULL, AI_INIT_GAME, (void *)iSpeciesID);
+            __AI_Callback(NULL, AI_INIT_GAME, (void *)(intptr_t)iSpeciesID);
           }
 
 	/* Check to see if it's this client. */
