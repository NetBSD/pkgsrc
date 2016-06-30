$NetBSD: patch-src_pal_src_thread_process.cpp,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/pal/src/thread/process.cpp.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/pal/src/thread/process.cpp
@@ -28,7 +28,6 @@ Abstract:
 #include "pal/process.h"
 #include "pal/init.h"
 #include "pal/critsect.h"
-#include "pal/debug.h"
 #include "pal/dbgmsg.h"
 #include "pal/utils.h"
 #include "pal/environ.h"
@@ -42,10 +41,8 @@ Abstract:
 #include "pal/fakepoll.h"
 #endif  // HAVE_POLL
 
-#include <unistd.h>
 #include <sys/mman.h>
 #include <sys/types.h>
-#include <sys/stat.h>
 #include <signal.h>
 #include <sys/wait.h>
 #include <sys/time.h>
@@ -93,12 +90,6 @@ PALAPI
 StartupHelperThread(
     LPVOID p);
 
-static 
-BOOL 
-GetProcessIdDisambiguationKey(
-    IN DWORD processId, 
-    OUT UINT64 *disambiguationKey);
-
 //
 // Helper memory page used by the FlushProcessWriteBuffers
 //
@@ -150,6 +141,10 @@ DWORD gSID = (DWORD) -1;
 #define CLR_SEM_MAX_NAMELEN (NAME_MAX - 4)
 #endif
 
+// The runtime waits on this semaphore if the dbgshim startup semaphore exists
+Volatile<sem_t *> g_continueSem = SEM_FAILED;
+char g_continueSemName[CLR_SEM_MAX_NAMELEN];
+
 // Function to call during PAL/process shutdown/abort
 Volatile<PSHUTDOWN_CALLBACK> g_shutdownCallback = nullptr;
 
@@ -1438,9 +1433,11 @@ static bool IsCoreClrModule(const char* 
 // Keep 31 length for Core 1.0 RC2 compatibility
 #if defined(__NetBSD__)
 static const char* RuntimeStartupSemaphoreName = "/clrst%08llx";
+static const char* RuntimeOldContinueSemaphoreName = "/clrco%08llx";
 static const char* RuntimeContinueSemaphoreName = "/clrco%08llx";
 #else
 static const char* RuntimeStartupSemaphoreName = "/clrst%08x%016llx";
+static const char* RuntimeOldContinueSemaphoreName = "/clrco%08x%016llx";
 static const char* RuntimeContinueSemaphoreName = "/clrco%08x%016llx";
 #endif
 
@@ -1453,8 +1450,6 @@ static uint64_t HashSemaphoreName(uint64
 #define HashSemaphoreName(a,b) a,b
 #endif
 
-static const char* PipeNameFormat = "/tmp/clr-debug-pipe-%d-%llu-%s";
-
 class PAL_RuntimeStartupHelper
 {
     LONG m_ref;
@@ -1463,6 +1458,7 @@ class PAL_RuntimeStartupHelper
     PVOID m_parameter;
     DWORD m_threadId;
     HANDLE m_threadHandle;
+
     DWORD m_processId;
 
     // A value that, used in conjunction with the process ID, uniquely identifies a process.
@@ -1472,10 +1468,6 @@ class PAL_RuntimeStartupHelper
     // Debugger waits on this semaphore and the runtime signals it on startup.
     sem_t *m_startupSem;
 
-    // Debuggee waits on this semaphore and the debugger signals it after the startup callback 
-    // registered (m_callback) returns.
-    sem_t *m_continueSem;
-
 public:
     PAL_RuntimeStartupHelper(DWORD dwProcessId, PPAL_STARTUP_CALLBACK pfnCallback, PVOID parameter) :
         m_ref(1),
@@ -1485,8 +1477,7 @@ public:
         m_threadId(0),
         m_threadHandle(NULL),
         m_processId(dwProcessId),
-        m_startupSem(SEM_FAILED),
-        m_continueSem(SEM_FAILED)
+        m_startupSem(SEM_FAILED)
     {
     }
 
@@ -1505,19 +1496,6 @@ public:
             sem_unlink(startupSemName);
         }
 
-        if (m_continueSem != SEM_FAILED)
-        {
-            char continueSemName[CLR_SEM_MAX_NAMELEN];
-            sprintf_s(continueSemName,
-                      sizeof(continueSemName),
-                      RuntimeContinueSemaphoreName,
-                      HashSemaphoreName(m_processId,
-                                        m_processIdDisambiguationKey));
-
-            sem_close(m_continueSem);
-            sem_unlink(continueSemName);
-        }
-
         if (m_threadHandle != NULL)
         {
             CloseHandle(m_threadHandle);
@@ -1575,7 +1553,6 @@ public:
     {
         CPalThread *pThread = InternalGetCurrentThread();
         char startupSemName[CLR_SEM_MAX_NAMELEN];
-        char continueSemName[CLR_SEM_MAX_NAMELEN];
         PAL_ERROR pe = NO_ERROR;
 
         // See semaphore name format for details about this value. We store it so that
@@ -1590,23 +1567,7 @@ public:
                   HashSemaphoreName(m_processId,
                                     m_processIdDisambiguationKey));
 
-        sprintf_s(continueSemName,
-                  sizeof(continueSemName),
-                  RuntimeContinueSemaphoreName,
-                  HashSemaphoreName(m_processId,
-                                    m_processIdDisambiguationKey));
-
-        TRACE("PAL_RuntimeStartupHelper.Register creating startup '%s' continue '%s'\n", startupSemName, continueSemName);
-
-        // Create the continue semaphore first so we don't race with PAL_NotifyRuntimeStarted. This open will fail if another 
-        // debugger is trying to attach to this process because the name will already exist.
-        m_continueSem = sem_open(continueSemName, O_CREAT | O_EXCL, S_IRWXU, 0);
-        if (m_continueSem == SEM_FAILED)
-        {
-            TRACE("sem_open(continue) failed: errno is %d (%s)\n", errno, strerror(errno));
-            pe = GetSemError();
-            goto exit;
-        }
+        TRACE("PAL_RuntimeStartupHelper.Register startup sem '%s'\n", startupSemName);
 
         // Create the debuggee startup semaphore so the runtime (debuggee) knows to wait for a debugger connection.
         m_startupSem = sem_open(startupSemName, O_CREAT | O_EXCL, S_IRWXU, 0);
@@ -1646,12 +1607,6 @@ public:
     {
         m_canceled = true;
 
-        // Tell the runtime to continue
-        if (sem_post(m_continueSem) != 0)
-        {
-            ASSERT("sem_post(continueSem) failed: errno is %d (%s)\n", errno, strerror(errno));
-        }
-
         // Tell the worker thread to continue
         if (sem_post(m_startupSem) != 0)
         {
@@ -1669,109 +1624,113 @@ public:
         }
     }
 
-    //
-    // There are a couple race conditions that need to be considered here:
-    //
-    // * On launch, between the fork and execv in the PAL's CreateProcess where the target process 
-    //   may contain a coreclr module image if the debugger process is running managed code. This 
-    //   makes just checking if the coreclr module exists not enough.
-    //
-    // * On launch (after the execv) or attach when the coreclr is loaded but before the DAC globals 
-    //   table is initialized where it is too soon to use/initialize the DAC on the debugger side.
-    //
-    // They are both fixed by check if the one of transport pipe files has been created.
-    //
-    bool IsCoreClrProcessReady()
-    {
-        char pipeName[MAX_DEBUGGER_TRANSPORT_PIPE_NAME_LENGTH];  
-
-        PAL_GetTransportPipeName(pipeName, m_processId, "in");
-
-        struct stat buf;
-        if (stat(pipeName, &buf) == 0) 
-        {
-            TRACE("IsCoreClrProcessReady: stat(%s) SUCCEEDED\n", pipeName);
-            return true;
-        }
-        TRACE("IsCoreClrProcessReady: stat(%s) FAILED: errno is %d (%s)\n", pipeName, errno, strerror(errno));
-        return false;
-    }
-
     PAL_ERROR InvokeStartupCallback()
     {
-        ProcessModules *listHead = NULL;
         PAL_ERROR pe = NO_ERROR;
-        DWORD count;
 
-        if (m_canceled)
+        if (!m_canceled)
         {
-            goto exit;
-        }
-
-        // Enumerate all the modules in the process and invoke the callback 
-        // for the coreclr module if found.
-        listHead = CreateProcessModules(m_processId, &count);
-        if (listHead == NULL)
-        {
-            TRACE("CreateProcessModules failed for pid %d\n", m_processId);
-            pe = ERROR_INVALID_PARAMETER;
-            goto exit;
-        }
+            // Enumerate all the modules in the process and invoke the callback 
+            // for the coreclr module if found.
+            DWORD count;
+            ProcessModules *listHead = CreateProcessModules(m_processId, &count);
+            if (listHead == NULL)
+            {
+                TRACE("CreateProcessModules failed for pid %d\n", m_processId);
+                pe = ERROR_INVALID_PARAMETER;
+                goto exit;
+            }
 
-        for (ProcessModules *entry = listHead; entry != NULL; entry = entry->Next)
-        {
-            if (IsCoreClrModule(entry->Name))
+            for (ProcessModules *entry = listHead; entry != NULL; entry = entry->Next)
             {
-                PAL_CPP_TRY
-                {
-                    TRACE("InvokeStartupCallback executing callback %p %s\n", entry->BaseAddress, entry->Name);
-                    m_callback(entry->Name, entry->BaseAddress, m_parameter);
-                }
-                PAL_CPP_CATCH_ALL
+                if (IsCoreClrModule(entry->Name))
                 {
+                    PAL_CPP_TRY
+                    {
+                        TRACE("InvokeStartupCallback executing callback %p %s\n", entry->BaseAddress, entry->Name);
+                        m_callback(entry->Name, entry->BaseAddress, m_parameter);
+                    }
+                        PAL_CPP_CATCH_ALL
+                    {
+                    }
+                    PAL_CPP_ENDTRY
+
+                        // Currently only the first coreclr module in a process is supported
+                        break;
                 }
-                PAL_CPP_ENDTRY
+            }
 
-                // Currently only the first coreclr module in a process is supported
-                break;
+        exit:
+            if (listHead != NULL)
+            {
+                DestroyProcessModules(listHead);
             }
         }
 
-    exit:
-        // Wake up the runtime 
-        if (sem_post(m_continueSem) != 0)
-        {
-            ASSERT("sem_post(continueSem) failed: errno is %d (%s)\n", errno, strerror(errno));
-        }
-        if (listHead != NULL)
-        {
-            DestroyProcessModules(listHead);
-        }
         return pe;
     }
 
     void StartupHelperThread()
     {
+        char continueSemName[CLR_SEM_MAX_NAMELEN];
+        sem_t *continueSem = SEM_FAILED;
         PAL_ERROR pe = NO_ERROR;
 
-        if (IsCoreClrProcessReady())
+        sprintf_s(continueSemName,
+                  sizeof(continueSemName),
+                  RuntimeContinueSemaphoreName,
+                  HashSemaphoreName(m_processId,
+                                    m_processIdDisambiguationKey));
+
+        TRACE("StartupHelperThread continue sem '%s'\n", continueSemName);
+
+        // Does the continue semaphore exists? If it does, the runtime is ready to be debugged.
+        continueSem = sem_open(continueSemName, 0);
+        if (continueSem != SEM_FAILED)
         {
+            TRACE("StartupHelperThread continue sem exists - invoking callback\n");
             pe = InvokeStartupCallback();
         }
-        else {
-            TRACE("sem_wait(startup)\n");
-
+        else if (errno == ENOENT)
+        {
             // Wait until the coreclr runtime (debuggee) starts up
             if (sem_wait(m_startupSem) == 0)
             {
-                pe = InvokeStartupCallback();
+                // The continue semaphore should exists now and is needed to wake up the runtimes below
+                continueSem = sem_open(continueSemName, 0);
+                if (continueSem != SEM_FAILED) 
+                {
+                    TRACE("StartupHelperThread continue sem exists after wait - invoking callback\n");
+                    pe = InvokeStartupCallback();
+                }
+                else
+                {
+                    TRACE("sem_open(continue) failed: errno is %d (%s)\n", errno, strerror(errno));
+                    pe = GetSemError();
+                }
             }
-            else
+            else 
             {
                 TRACE("sem_wait(startup) failed: errno is %d (%s)\n", errno, strerror(errno));
                 pe = GetSemError();
             }
         }
+        else
+        {
+            pe = GetSemError();
+        }
+
+        // Wake up the runtime even on error and cancelation
+        if (continueSem != SEM_FAILED)
+        {
+            if (sem_post(continueSem) != 0)
+            {
+                TRACE("sem_post(continueSem) failed: errno is %d (%s)\n", errno, strerror(errno));
+                pe = GetSemError();
+            }
+
+            sem_close(continueSem);
+        }
 
         // Invoke the callback on errors
         if (pe != NO_ERROR && !m_canceled)
@@ -1886,19 +1845,35 @@ PALAPI
 PAL_NotifyRuntimeStarted()
 {
     char startupSemName[CLR_SEM_MAX_NAMELEN];
-    char continueSemName[CLR_SEM_MAX_NAMELEN];
     sem_t *startupSem = SEM_FAILED;
-    sem_t *continueSem = SEM_FAILED;
     BOOL result = TRUE;
 
     UINT64 processIdDisambiguationKey = 0;
     GetProcessIdDisambiguationKey(gPID, &processIdDisambiguationKey);
 
     sprintf_s(startupSemName, sizeof(startupSemName), RuntimeStartupSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
-    sprintf_s(continueSemName, sizeof(continueSemName), RuntimeContinueSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
+    sprintf_s(g_continueSemName, sizeof(g_continueSemName), RuntimeOldContinueSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
 
-    TRACE("PAL_NotifyRuntimeStarted opening continue '%s' startup '%s'\n", continueSemName, startupSemName);
+    TRACE("PAL_NotifyRuntimeStarted opening continue (old) '%s' startup '%s'\n", g_continueSemName, startupSemName);
 
+    // For backwards compatibility with RC2 (see issue #4410) first OPEN the continue semaphore with the old name "clrcoXXXX".
+    g_continueSem = sem_open(g_continueSemName, 0);
+    if (g_continueSem == SEM_FAILED)
+    {
+        // Create the new continue semaphore name "clrctXXXX"
+        sprintf_s(g_continueSemName, sizeof(g_continueSemName), RuntimeContinueSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
+
+        TRACE("PAL_NotifyRuntimeStarted creating continue '%s'\n", g_continueSemName);
+
+        // Create the continue semaphore. This tells dbgshim that coreclr is initialized and ready.
+        g_continueSem = sem_open(g_continueSemName, O_CREAT | O_EXCL, S_IRWXU, 0);
+        if (g_continueSem == SEM_FAILED)
+        {
+            ASSERT("sem_open(%s) failed: %d (%s)\n", g_continueSemName, errno, strerror(errno));
+            result = FALSE;
+            goto exit;
+        }
+    }
 
     // Open the debugger startup semaphore. If it doesn't exists, then we do nothing and
     // the function is successful.
@@ -1909,14 +1884,6 @@ PAL_NotifyRuntimeStarted()
         goto exit;
     }
 
-    continueSem = sem_open(continueSemName, 0);
-    if (continueSem == SEM_FAILED)
-    {
-        ASSERT("sem_open(%s) failed: %d (%s)\n", continueSemName, errno, strerror(errno));
-        result = FALSE;
-        goto exit;
-    }
-
     // Wake up the debugger waiting for startup
     if (sem_post(startupSem) != 0)
     {
@@ -1926,7 +1893,7 @@ PAL_NotifyRuntimeStarted()
     }
 
     // Now wait until the debugger's runtime startup notification is finished
-    if (sem_wait(continueSem) != 0)
+    if (sem_wait(g_continueSem) != 0)
     {
         ASSERT("sem_wait(continueSem) failed: errno is %d (%s)\n", errno, strerror(errno));
         result = FALSE;
@@ -1938,14 +1905,41 @@ exit:
     {
         sem_close(startupSem);
     }
-    if (continueSem != SEM_FAILED)
-    {
-        sem_close(continueSem);
-    }
     return result;
 }
 
 /*++
+    PAL_CleanupTargetProcess
+
+    Cleanup the target process's name continue semaphore
+    on the debugger side when the debugger detects the
+    process termination.
+
+Parameters:
+    pid - process id
+    disambiguationKey - key to make process id unique
+
+Return value:
+    None
+--*/
+VOID
+PALAPI
+PAL_CleanupTargetProcess(
+    IN int pid,
+    IN UINT64 disambiguationKey)
+{
+    char continueSemName[NAME_MAX - 4];
+
+    sprintf_s(continueSemName,
+              sizeof(continueSemName),
+              RuntimeContinueSemaphoreName,
+              pid,
+              disambiguationKey);
+
+    sem_unlink(continueSemName);
+}
+
+/*++
  Function:
   GetProcessIdDisambiguationKey
 
@@ -2018,7 +2012,7 @@ GetProcessIdDisambiguationKey(DWORD proc
 
     return TRUE;
 
-#elif HAVE_PROCFS_STAT
+#elif defined(HAVE_PROCFS_CTL)
 
     // Here we read /proc/<pid>/stat file to get the start time for the process.
     // We return this value (which is expressed in jiffies since boot time).
@@ -2072,34 +2066,12 @@ GetProcessIdDisambiguationKey(DWORD proc
 
 #else
     // If this is not OS X and we don't have /proc, we just return FALSE.
-    WARN("GetProcessIdDisambiguationKey was called but is not implemented on this platform!");
+    WARN(!"GetProcessIdDisambiguationKey was called but is not implemented on this platform!");
     return FALSE;
 #endif
 }
 
 /*++
- Function:
-  PAL_GetTransportPipeName 
-
-  Builds the transport pipe names from the process id.
---*/
-void 
-PALAPI
-PAL_GetTransportPipeName(char *name, DWORD id, const char *suffix)
-{
-    UINT64 disambiguationKey = 0;
-    BOOL ret = GetProcessIdDisambiguationKey(id, &disambiguationKey);
-
-    // If GetProcessIdDisambiguationKey failed for some reason, it should set the value 
-    // to 0. We expect that anyone else making the pipe name will also fail and thus will
-    // also try to use 0 as the value.
-    _ASSERTE(ret == TRUE || disambiguationKey == 0);
-
-    int chars = _snprintf(name, MAX_DEBUGGER_TRANSPORT_PIPE_NAME_LENGTH, PipeNameFormat, id, disambiguationKey, suffix);
-    _ASSERTE(chars > 0 && chars < MAX_DEBUGGER_TRANSPORT_PIPE_NAME_LENGTH);
-}
-
-/*++
 Function:
   GetProcessTimes
 
@@ -2726,9 +2698,8 @@ CreateProcessModules(
 
     free(line); // We didn't allocate line, but as per contract of getline we should free it
     pclose(vmmapFile);
-exit:
 
-#elif HAVE_PROCFS_MAPS 
+#elif defined(HAVE_PROCFS_CTL)
 
     // Here we read /proc/<pid>/maps file in order to parse it and figure out what it says 
     // about a library we are looking for. This file looks something like this:
@@ -2807,11 +2778,10 @@ exit:
 
     free(line); // We didn't allocate line, but as per contract of getline we should free it
     fclose(mapsFile);
-exit:
-
 #else
     _ASSERTE(!"Not implemented on this platform");
 #endif
+exit:
     return listHead;
 }
 
@@ -2855,6 +2825,14 @@ void PROCNotifyProcessShutdown()
     {
         callback();
     }
+
+    // Cleanup the name continue semaphore on exit and abormal terminatation
+    sem_t *continueSem = InterlockedExchangePointer(&g_continueSem, SEM_FAILED);
+    if (continueSem != SEM_FAILED)
+    {
+        sem_close(continueSem);
+        sem_unlink(g_continueSemName);
+    }
 }
 
 /*++
