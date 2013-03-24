$NetBSD: patch-CommonUtilitiesLib_Task.cpp,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- CommonUtilitiesLib/Task.cpp.orig	2005-05-31 10:54:25.000000000 +0000
+++ CommonUtilitiesLib/Task.cpp
@@ -104,7 +104,7 @@ void Task::Signal(EventFlags events)
             // Task needs to be placed on a particular thread.
          {
             if (TASK_DEBUG) if (fTaskName[0] == 0) ::strcpy(fTaskName, " corrupt task");
-            if (TASK_DEBUG) qtss_printf("Task::Signal enque TaskName=%s fUseThisThread=%lu q elem=%lu enclosing=%lu\n", fTaskName, (UInt32) fUseThisThread, (UInt32) &fTaskQueueElem, (UInt32) this);
+            if (TASK_DEBUG) qtss_printf("Task::Signal enque TaskName=%s fUseThisThread=%lu q elem=%lu enclosing=%lu\n", fTaskName, (UInt32)(uintptr_t) fUseThisThread, (UInt32)(uintptr_t) &fTaskQueueElem, (UInt32)(uintptr_t) this);
             fUseThisThread->fTaskQueue.EnQueue(&fTaskQueueElem);
         }
         else
@@ -113,12 +113,12 @@ void Task::Signal(EventFlags events)
             unsigned int theThread = atomic_add(&sThreadPicker, 1);
             theThread %= TaskThreadPool::sNumTaskThreads;
             if (TASK_DEBUG) if (fTaskName[0] == 0) ::strcpy(fTaskName, " corrupt task");
-            if (TASK_DEBUG) qtss_printf("Task::Signal enque TaskName=%s thread=%lu q elem=%lu enclosing=%lu\n", fTaskName, (UInt32)TaskThreadPool::sTaskThreadArray[theThread],(UInt32) &fTaskQueueElem,(UInt32) this);
+            if (TASK_DEBUG) qtss_printf("Task::Signal enque TaskName=%s thread=%lu q elem=%lu enclosing=%lu\n", fTaskName, (UInt32)(uintptr_t)TaskThreadPool::sTaskThreadArray[theThread],(UInt32)(uintptr_t) &fTaskQueueElem,(UInt32)(uintptr_t) this);
             TaskThreadPool::sTaskThreadArray[theThread]->fTaskQueue.EnQueue(&fTaskQueueElem);
         }
     }
     else
-        if (TASK_DEBUG) qtss_printf("Task::Signal sent to dead TaskName=%s  q elem=%lu  enclosing=%lu\n",  fTaskName, (UInt32) &fTaskQueueElem, (UInt32) this);
+        if (TASK_DEBUG) qtss_printf("Task::Signal sent to dead TaskName=%s  q elem=%lu  enclosing=%lu\n",  fTaskName, (UInt32)(uintptr_t) &fTaskQueueElem, (UInt32)(uintptr_t) this);
         
 
 }
@@ -165,7 +165,7 @@ void TaskThread::Entry()
             if (theTask->fWriteLock)
             {   
                 OSMutexWriteLocker mutexLocker(&TaskThreadPool::sMutexRW);
-                if (TASK_DEBUG) qtss_printf("TaskThread::Entry run global locked TaskName=%s CurMSec=%.3f thread=%ld task=%ld\n", theTask->fTaskName, OS::StartTimeMilli_Float() ,(SInt32) this,(SInt32) theTask);
+                if (TASK_DEBUG) qtss_printf("TaskThread::Entry run global locked TaskName=%s CurMSec=%.3f thread=%ld task=%ld\n", theTask->fTaskName, OS::StartTimeMilli_Float() ,(SInt32)(uintptr_t) this,(SInt32)(uintptr_t) theTask);
                 
                 theTimeout = theTask->Run();
                 theTask->fWriteLock = false;
@@ -173,7 +173,7 @@ void TaskThread::Entry()
             else
             {
                 OSMutexReadLocker mutexLocker(&TaskThreadPool::sMutexRW);
-                if (TASK_DEBUG) qtss_printf("TaskThread::Entry run TaskName=%s CurMSec=%.3f thread=%ld task=%ld\n", theTask->fTaskName, OS::StartTimeMilli_Float(), (SInt32) this,(SInt32) theTask);
+                if (TASK_DEBUG) qtss_printf("TaskThread::Entry run TaskName=%s CurMSec=%.3f thread=%ld task=%ld\n", theTask->fTaskName, OS::StartTimeMilli_Float(), (SInt32)(uintptr_t) this,(SInt32)(uintptr_t) theTask);
 
                 theTimeout = theTask->Run();
             
@@ -187,7 +187,7 @@ void TaskThread::Entry()
             {
                 if (TASK_DEBUG) 
                 {
-                    qtss_printf("TaskThread::Entry delete TaskName=%s CurMSec=%.3f thread=%ld task=%ld\n", theTask->fTaskName, OS::StartTimeMilli_Float(), (SInt32) this, (SInt32) theTask);
+                    qtss_printf("TaskThread::Entry delete TaskName=%s CurMSec=%.3f thread=%ld task=%ld\n", theTask->fTaskName, OS::StartTimeMilli_Float(), (SInt32)(uintptr_t) this, (SInt32)(uintptr_t) theTask);
                      
                     theTask->fUseThisThread = NULL;
                     
@@ -226,7 +226,7 @@ void TaskThread::Entry()
             {
                 //note that if we get here, we don't reset theTask, so it will get passed into
                 //WaitForTask
-                if (TASK_DEBUG) qtss_printf("TaskThread::Entry insert TaskName=%s in timer heap thread=%lu elem=%lu task=%ld timeout=%.2f\n", theTask->fTaskName,  (UInt32) this, (UInt32) &theTask->fTimerHeapElem,(SInt32) theTask, (float)theTimeout / (float) 1000);
+                if (TASK_DEBUG) qtss_printf("TaskThread::Entry insert TaskName=%s in timer heap thread=%lu elem=%lu task=%ld timeout=%.2f\n", theTask->fTaskName,  (UInt32)(uintptr_t) this, (UInt32)(uintptr_t) &theTask->fTimerHeapElem,(SInt32)(uintptr_t) theTask, (float)theTimeout / (float) 1000);
                 theTask->fTimerHeapElem.SetValue(OS::Milliseconds() + theTimeout);
                 fHeap.Insert(&theTask->fTimerHeapElem);
                 (void)atomic_or(&theTask->fEvents, Task::kIdleEvent);
@@ -264,7 +264,7 @@ Task* TaskThread::WaitForTask()
         
         if ((fHeap.PeekMin() != NULL) && (fHeap.PeekMin()->GetValue() <= theCurrentTime))
         {    
-            if (TASK_DEBUG) qtss_printf("TaskThread::WaitForTask found timer-task=%s thread %lu fHeap.CurrentHeapSize(%lu) taskElem = %lu enclose=%lu\n",((Task*)fHeap.PeekMin()->GetEnclosingObject())->fTaskName, (UInt32) this, fHeap.CurrentHeapSize(), (UInt32) fHeap.PeekMin(), (UInt32) fHeap.PeekMin()->GetEnclosingObject());
+            if (TASK_DEBUG) qtss_printf("TaskThread::WaitForTask found timer-task=%s thread %lu fHeap.CurrentHeapSize(%lu) taskElem = %lu enclose=%lu\n",((Task*)fHeap.PeekMin()->GetEnclosingObject())->fTaskName, (UInt32)(uintptr_t) this, fHeap.CurrentHeapSize(), (UInt32)(uintptr_t) fHeap.PeekMin(), (UInt32)(uintptr_t) fHeap.PeekMin()->GetEnclosingObject());
             return (Task*)fHeap.ExtractMin()->GetEnclosingObject();
         }
     
@@ -286,7 +286,7 @@ Task* TaskThread::WaitForTask()
         OSQueueElem* theElem = fTaskQueue.DeQueueBlocking(this, (SInt32) theTimeout);
         if (theElem != NULL)
         {    
-            if (TASK_DEBUG) qtss_printf("TaskThread::WaitForTask found signal-task=%s thread %lu fTaskQueue.GetLength(%lu) taskElem = %lu enclose=%lu\n", ((Task*)theElem->GetEnclosingObject())->fTaskName,  (UInt32) this, fTaskQueue.GetQueue()->GetLength(), (UInt32)  theElem,  (UInt32)theElem->GetEnclosingObject() );
+            if (TASK_DEBUG) qtss_printf("TaskThread::WaitForTask found signal-task=%s thread %lu fTaskQueue.GetLength(%lu) taskElem = %lu enclose=%lu\n", ((Task*)theElem->GetEnclosingObject())->fTaskName,  (UInt32)(uintptr_t) this, fTaskQueue.GetQueue()->GetLength(), (UInt32)(uintptr_t)  theElem,  (UInt32)(uintptr_t)theElem->GetEnclosingObject() );
             return (Task*)theElem->GetEnclosingObject();
         }
 
