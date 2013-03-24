$NetBSD: patch-CommonUtilitiesLib_EventContext.h,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- CommonUtilitiesLib/EventContext.h.orig	2005-05-18 08:01:14.000000000 +0000
+++ CommonUtilitiesLib/EventContext.h
@@ -83,9 +83,9 @@ class EventContext
             if (EVENTCONTEXT_DEBUG)
             {
                 if (fTask== NULL)  
-                    qtss_printf("EventContext::SetTask context=%lu task= NULL\n", (UInt32) this); 
+                    qtss_printf("EventContext::SetTask context=%lu task= NULL\n", (UInt32)(uintptr_t) this); 
                 else 
-                    qtss_printf("EventContext::SetTask context=%lu task= %lu name=%s\n",(UInt32) this,(UInt32) fTask, fTask->fTaskName); 
+                    qtss_printf("EventContext::SetTask context=%lu task= %lu name=%s\n",(UInt32)(uintptr_t) this,(UInt32)(uintptr_t) fTask, fTask->fTaskName); 
             }
         }
         
@@ -119,9 +119,9 @@ class EventContext
             if (EVENTCONTEXT_DEBUG)
             {
                 if (fTask== NULL)  
-                    qtss_printf("EventContext::ProcessEvent context=%lu task=NULL\n",(UInt32) this); 
+                    qtss_printf("EventContext::ProcessEvent context=%lu task=NULL\n",(UInt32)(uintptr_t) this); 
                 else 
-                    qtss_printf("EventContext::ProcessEvent context=%lu task=%lu TaskName=%s\n",(UInt32)this,(UInt32) fTask, fTask->fTaskName); 
+                    qtss_printf("EventContext::ProcessEvent context=%lu task=%lu TaskName=%s\n",(UInt32)(uintptr_t)this,(UInt32)(uintptr_t) fTask, fTask->fTaskName); 
             }
 
             if (fTask != NULL)
