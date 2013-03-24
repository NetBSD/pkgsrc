$NetBSD: patch-CommonUtilitiesLib_Task.h,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- CommonUtilitiesLib/Task.h.orig	2005-05-27 04:07:59.000000000 +0000
+++ CommonUtilitiesLib/Task.h
@@ -116,7 +116,7 @@ class Task
                                                         fUseThisThread = (TaskThread*)OSThread::GetCurrent();
                                                         Assert(fUseThisThread != NULL);
                                                         if (TASK_DEBUG) if (fTaskName[0] == 0) ::strcpy(fTaskName, " corrupt task");
-                                                        if (TASK_DEBUG) qtss_printf("Task::ForceSameThread fUseThisThread %lu task %s enque elem=%lu enclosing %lu\n", (UInt32)fUseThisThread, fTaskName,(UInt32) &fTaskQueueElem,(UInt32) this);
+                                                        if (TASK_DEBUG) qtss_printf("Task::ForceSameThread fUseThisThread %lu task %s enque elem=%lu enclosing %lu\n", (UInt32)(uintptr_t)fUseThisThread, fTaskName,(UInt32)(uintptr_t) &fTaskQueueElem,(UInt32)(uintptr_t) this);
                                                     }
         SInt64                  CallLocked()        {   ForceSameThread();
                                                         fWriteLock = true;
